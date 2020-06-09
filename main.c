#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    
    int operacoes;   // Variável que armazena o número de operações a serem realizadas no grafo.
    int operacao;    // Variável que armazena a operação a ser realizada no grafo.
    int no1, no2;    // Variáveis que armazenam o valor de dois vértices para a inserção de uma aresta.
    int numVertices; // Variável que armazena o número de Vértices.
    int numArestas;  // Variável que armazena o número de Arestas.
    GRAFO* g;        // Armazena a estrutura de dados de um grafo.
    
    g = NULL;
    
    while(1)
    {
    
        printf("\nDigite: \n0 - Para sair do programa.\n1 - Para criar um grafo.\n2 - Para inserir uma aresta.\n3 - Para remover uma aresta.\n4 - Para imprimir o Grafo.\n5 - Para fazer uma busca em profundidade.\n");
        scanf("%d", &operacao);
        printf("\n");

        switch(operacao)
        {
            case 0:
                grafo_deletar(&g);
                break;
            case 1:
            
                if(g == NULL)
                {
                    printf("Digite o número de Vertices do Grafo: ");
                    scanf("%d", &numVertices);
                    g = grafo_criar(numVertices);
                }else
                {
                    printf("Falha ao realizar esta operação, já há um Grafo existente.\n");
                }
                break;                

            case 2:

                printf("Digite o primeiro Vertice: ");
                scanf("%d", &no1);
                printf("Digite o segundo Vertice: ");
                scanf("%d", &no2);
                if(grafo_inserir_aresta(g, no1, no2)) printf("Falha ao inserir a aresta.\n");
                else printf("Aresta inserida com sucesso.\n");
                break;
            
            case 3:
                printf("Digite a aresta a ser removida (int int): ");
                scanf("%d %d", &no1, &no2);
                grafo_remover_aresta(g, no1, no2);
                break;
            case 4:
                grafo_imprimir(g);
                break;
            case 5:
                printf("Insira o vértice inicial: ");
                scanf("%d", &no1);
                grafo_DFS(g, no1);
                break;
        }
    }

    grafo_deletar(&g);

    return 0;
}