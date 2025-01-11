#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListaAresta {
    int destino;
    int custo;
    struct ListaAresta *prox;
} ListaAresta;

// Inicializa o grafo com n vértices
void InicializarGrafo(ListaAresta **grafo, int n) {
    for (int i = 0; i <= n; i++) {
        grafo[i] = NULL;
    }
}

// Função auxiliar para inserir um nó na lista de adjacência
ListaAresta *InserirNaLista(ListaAresta *lista, int destino, int custo) {
    ListaAresta *novoNo = (ListaAresta *)malloc(sizeof(ListaAresta));
    novoNo->destino = destino;
    novoNo->custo = custo;
    novoNo->prox = lista;
    return novoNo;
}

// Caso 1:
void InserirAresta(ListaAresta **grafo, int origem, int destino, int custo) {
    grafo[origem] = InserirNaLista(grafo[origem], destino, custo);
}

// Caso 2:
void RemoverAresta(ListaAresta **grafo, int origem, int destino) {
    ListaAresta *atual = grafo[origem];
    ListaAresta *anterior = NULL;
    while (atual != NULL && atual->destino != destino) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            grafo[origem] = atual->prox;
        }
        else {
            anterior->prox = atual->prox;
        }

        free(atual);
        printf("Aresta removida com sucesso.\n");
    }
    else {
        printf("Aresta nao encontrada.\n");
    }
}

// Imprimir a lista de adjacência de um vértice
void ImprimirListaArestas(ListaAresta *lista) {
    if (lista != NULL) {
        printf("-(%d, %d)", lista->destino, lista->custo);
        ImprimirListaArestas(lista->prox);
    }
}

// Caso 3:
void ImprimirGrafo(ListaAresta **grafo, int n) {
    printf("Grafo:\n");
    for (int i = 1; i <= n; i++) {
        printf("\t%d", i);
        ImprimirListaArestas(grafo[i]);
        printf("\n");
    }
}

// Caso 4:
void ImprimirGrausVertice(ListaAresta **grafo, int n, int vertice) {
    int grauEntrada = 0;
    int grauSaida = 0;
    ListaAresta *atual;
    atual = grafo[vertice];

    while (atual != NULL) {
        grauSaida++;
        atual = atual->prox;
    }
    for (int i = 1; i <= n; i++) {
        atual = grafo[i];
        while (atual != NULL) {
            if (atual->destino == vertice) {
                grauEntrada++;
            }

            atual = atual->prox;
        }
    }

    printf("Vertice %d: Grau de Saida = %d, Grau de Entrada = %d\n", vertice, grauSaida, grauEntrada);
}

// Caso 5:
int VerificarGrafoCompleto(ListaAresta **grafo, int n) {
    for (int i = 1; i <= n; i++) {
        int contagem = 0;
        ListaAresta *atual = grafo[i];
        while (atual != NULL) {
            contagem++;
            atual = atual->prox;
        }

        if (contagem != n - 1) {
            return 0;
        }
    }
    return 1;
}

// Função auxiliar para imprimir todos os caminhos
void DFS_TodosCaminhos(ListaAresta **grafo, int atual, int destino, int *visitado, int *caminho, int posicao) {
    visitado[atual] = 1;
    caminho[posicao] = atual;
    posicao++;

    if (atual == destino) {
        for (int i = 0; i < posicao; i++) {
            printf("%d ", caminho[i]);
        }

        printf("\n");
    }
    else {
        ListaAresta *vizinho = grafo[atual];
        while (vizinho != NULL) {
            if (!visitado[vizinho->destino]) {
                DFS_TodosCaminhos(grafo, vizinho->destino, destino, visitado, caminho, posicao);
            }

            vizinho = vizinho->prox;
        }
    }
    visitado[atual] = 0;
}

// Caso 6:
void ImprimirTodosCaminhos(ListaAresta **grafo, int n, int origem, int destino) {
    int *visitado = (int *)malloc((n + 1) * sizeof(int));
    int *caminho = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        visitado[i] = 0;
    }

    DFS_TodosCaminhos(grafo, origem, destino, visitado, caminho, 0);
    free(visitado);
    free(caminho);
}

// Caso 7:
void ImprimirCaminhoMaisCurto(ListaAresta **grafo, int n, int origem, int destino) {
    int *distancia = (int *)malloc((n + 1) * sizeof(int));
    int *anterior = (int *)malloc((n + 1) * sizeof(int));
    int *fila = (int *)malloc((n + 1) * sizeof(int));
    int frente = 0, tras = 0;

    for (int i = 0; i <= n; i++) {
        distancia[i] = INT_MAX;
        anterior[i] = -1;
    }
    distancia[origem] = 0;
    fila[tras++] = origem;
    while (frente != tras) {
        int u = fila[frente++];
        ListaAresta *vizinho = grafo[u];

        while (vizinho != NULL) {
            if (distancia[vizinho->destino] == INT_MAX) {
                distancia[vizinho->destino] = distancia[u] + 1;
                anterior[vizinho->destino] = u;
                fila[tras++] = vizinho->destino;
            }

            vizinho = vizinho->prox;
        }
    }

    if (distancia[destino] == INT_MAX) {
        printf("Nao existe caminho de %d para %d\n", origem, destino);
    }
    else {
        printf("Caminho mais curto de %d para %d:\n", origem, destino);
        int caminho[n + 1];
        int tam = 0;
        for (int v = destino; v != -1; v = anterior[v]) {
            caminho[tam++] = v;
        }

        for (int i = tam - 1; i >= 0; i--) {
            printf("%d ", caminho[i]);
        }

        printf("\n");
    }

    free(distancia);
    free(anterior);
    free(fila);
}

// Caso 8:
void ImprimirCaminhoMenorCusto(ListaAresta **grafo, int n, int origem, int destino) {
    int *distancia = (int *)malloc((n + 1) * sizeof(int));
    int *anterior = (int *)malloc((n + 1) * sizeof(int));
    int *visitado = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        distancia[i] = INT_MAX;
        anterior[i] = -1;
        visitado[i] = 0;
    }

    distancia[origem] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                u = j;
            }
        }

        if (u == -1 || distancia[u] == INT_MAX)
            break;

        visitado[u] = 1;
        ListaAresta *vizinho = grafo[u];
        while (vizinho != NULL) {
            if (distancia[u] + vizinho->custo < distancia[vizinho->destino]) {
                distancia[vizinho->destino] = distancia[u] + vizinho->custo;
                anterior[vizinho->destino] = u;
            }

            vizinho = vizinho->prox;
        }
    }
    if (distancia[destino] == INT_MAX) {
        printf("Nao existe caminho de %d para %d\n", origem, destino);
    }
    else {
        printf("Caminho de menor custo de %d para %d:\n", origem, destino);
        int caminho[n + 1];
        int tam = 0;
        for (int v = destino; v != -1; v = anterior[v]) {
            caminho[tam++] = v;
        }

        for (int i = tam - 1; i >= 0; i--) {
            printf("%d ", caminho[i]);
        }

        printf("\nCusto: %d\n", distancia[destino]);
    }

    free(distancia);
    free(anterior);
    free(visitado);
}

int main() {
    int n = 5; // Número de vértices do grafo
    ListaAresta *grafo[n+1];
    InicializarGrafo(grafo, n);
    int opcao;
    int origem, destino, custo, vertice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir aresta no grafo\n");
        printf("2. Remover aresta do grafo\n");
        printf("3. Imprimir grafo\n");
        printf("4. Imprimir graus de entrada e saida de um vertice\n");
        printf("5. Verificar se o grafo e completo\n");
        printf("6. Imprimir todos os caminhos entre uma origem e um destino\n");
        printf("7. Imprimir o caminho mais curto (menor numero de arestas)\n");
        printf("8. Imprimir o caminho de menor custo\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite a origem, destino e custo da aresta: ");
                scanf("%d %d %d", &origem, &destino, &custo);
                InserirAresta(grafo, origem, destino, custo);
                break;

            case 2:
                printf("Digite a origem e destino da aresta a remover: ");
                scanf("%d %d", &origem, &destino);
                RemoverAresta(grafo, origem, destino);
                break;

            case 3:
                ImprimirGrafo(grafo, n);
                break;

            case 4:
                printf("Digite o vertice: ");
                scanf("%d", &vertice);
                ImprimirGrausVertice(grafo, n, vertice);
                break;

            case 5:
                if (VerificarGrafoCompleto(grafo, n)) {
                    printf("O grafo e completo.\n");
                }
                else {
                    printf("O grafo nao e completo.\n");
                }
                break;

            case 6:
                printf("Digite a origem e o destino: ");
                scanf("%d %d", &origem, &destino);
                printf("Caminhos de %d para %d:\n", origem, destino);
                ImprimirTodosCaminhos(grafo, n, origem, destino);
                break;

            case 7:
                printf("Digite a origem e o destino: ");
                scanf("%d %d", &origem, &destino);
                ImprimirCaminhoMaisCurto(grafo, n, origem, destino);
                break;

            case 8:
                printf("Digite a origem e o destino: ");
                scanf("%d %d", &origem, &destino);
                ImprimirCaminhoMenorCusto(grafo, n, origem, destino);
                break;

            case 9:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    while (opcao != 9);
    for (int i = 0; i <= n; i++) {
        ListaAresta *temp;

        while (grafo[i] != NULL) {
            temp = grafo[i];
            grafo[i] = grafo[i]->prox;
            free(temp);
        }
    }

    return 0;
}
