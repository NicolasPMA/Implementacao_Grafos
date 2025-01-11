# Implementacao_Grafos
 Este é um código feito para implementar os conceitos estudados sobre Grafos.

 ## 🚀 Funcionalidade
- Insere uma aresta no grafo.
- Remove uma aresta do grafo.
- Imprime o grafo.
- Imprime os graus de entrada e saída de um vértice.
- Verifica se o grafo é completo.
- Imprimi todos os caminhos entre uma origem e um destino.
- Imprimi o caminho mais curto.
- Imprimi o caminho de menor custo.

## 💻 Tecnologia utilizada
- C: Linguagem de programação principal.

 ## 💡 Como funciona
O código é inicalizado por padrão com um grafo de 5 nós (1, 2, 3, 4 e 5) sem arestas.
 
Quando rodar o código, um menu de opções será apresentado.
1. Inserir aresta no grafo
- O usuário deve fornecer separadamente os valores de origem, destino e custo (digita o valor desejado e envia 3x).
- Por padrão o grafo contém os nós 1, 2, 3, 4 e 5.
- "1" (origem) "5" (destino) "10" (custo).

2. Remover aresta do grafo
- O usuário deve fornecer separadamente os valores de origem e destino da aresta.
- "1" (origem) "5" (destino).
 
3. Imprimir grafo
- Imprime o grafo.

4. Imprimir graus de entrada e saida de um vertice
- O usuário deve fornecer o valor do vértice desejado para ver os graus de entrada e saída do mesmo.
   
5. Verificar se o grafo e completo
- Verifica se o grafo é completo.
    
6. Imprimir todos os caminhos entre uma origem e um destino
- Imprime todos os caminhos entre uma origem e um destino.
- "1" "5" (todos os caminhos possíveis para ir do vértice 1 até o vértice 5).
    
7. Imprimir o caminho mais curto (menor numero de arestas)
- Imprime o caminho mais curto entre uma origem e um destino.
- "1" "5" (imprime o menor caminho que vai do vértice 1 até o vértice 5).
    
8. Imprimir o caminho de menor custo
- Imprime o caminho de menor custo entre uma origem e um destino.
- "1" "5" (imprime o caminho que tenha o menor custo ao ir do vértice 1 até o vértice 5).

9. Sair


## ⚙ Como o código funciona

O código é feito a partir dos conceitos gerais de grafos. O código é inicalizado com uma estrutura padrão de grafo com os vértices (1, 2, 3, 4 e 5) sem arestas conectando-os.
O formato utilizado do grafo é do formato 1-(5, 10), ou seja, origem: 1, destino: 5 e custo: 10.
Conceitos utilizados:
- Conceitos gerais de Grafos.
