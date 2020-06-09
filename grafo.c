#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "lista.h"

/*
 *      Implementação de um Grafo Direcionado utilizando listas de adjascẽncias * 
 */

struct grafo_
{
    int vertices;
    int arestas;

    LISTA** listas_de_adjascencia;
};

GRAFO* grafo_criar(int n) // Cria um grafo com n vértices
{
    GRAFO* g = (GRAFO*) malloc(sizeof(GRAFO));

    if(n >= 0 && g != NULL)
    {
        g->vertices = n;
        g->arestas = 0;

        g->listas_de_adjascencia = (LISTA**) malloc(sizeof(LISTA*) * g->vertices);

        for(int i = 0; i < g->vertices; i++) // Loop que cria as listas de adjascencia.
        {
            g->listas_de_adjascencia[i] = lista_criar();
            if(g-> listas_de_adjascencia[i] == NULL) return NULL;
        }
        return g;
    }
    
    return  NULL;
}

/*
*   Função que insere uma aresta no grafo.
*   Retorna 0 caso a inserção seja realizada sem problemas e, caso contrário, retorna 1;
*/
int grafo_inserir_aresta(GRAFO* g, int no1, int no2) // Insere uma dada aresta.
{
    if(g != NULL)
    {
        if(lista_inserir_fim(g->listas_de_adjascencia[no1], no2)) return 1;

        g->arestas++;
        return 0;
    }

    return 1;
}

/*
*   Função que realiza a remoção de um dado elemento no grafo.
*   Retorna 0 caso a remoção tenha ocorrido sem problemas e, caso contrário, retorna 1;
*/
int grafo_remover_aresta(GRAFO* g, int no1, int no2) // Remove uma dada aresta.
{
    if(g != NULL)
    {
        if(lista_remover(g->listas_de_adjascencia[no1], no2)) return 1;
        g->arestas--;

        return 0;
    }

    return 1;
}

void grafo_imprimir(GRAFO* g) // Imprime a lista de adjascência.
{

    if(g != NULL)
    {    
        for(int i = 0; i < g->vertices; i++)
        {
            printf("%d:", i);
            lista_imprimir(g->listas_de_adjascencia[i]);
            printf("\n");
        }
    }

    printf("\n");
    return;
}

void subrotina_DFS(GRAFO* G, int vertice, int* tempo, COR* rotulos, int* antecessor, int* descoberta, int* termino)
{
    int proximo;
    rotulos[vertice] = CINZA;
    (*tempo)++;
    descoberta[vertice] = *tempo;
    

    proximo = lista_primeiro_item(G->listas_de_adjascencia[vertice]);
    while(proximo != ERRO)
    {
        antecessor[proximo] = vertice;
        if(rotulos[proximo] == BRANCO)
        {
            subrotina_DFS(G, proximo, tempo, rotulos, antecessor, descoberta, termino);
        }
        proximo = lista_proximo(G->listas_de_adjascencia[vertice]);
    }

    rotulos[vertice] = PRETO;    
    (*tempo)++;
    termino[vertice] = *tempo;

    printf("No %d, descoberta = %d, termino = %d, antecessor = %d.\n", vertice, descoberta[vertice], termino[vertice], antecessor[vertice]);
}

void grafo_DFS(GRAFO* g, int vertice)
{
    // Os vetores a seguir auxiliarão na execução do programa:
    COR* rotulos;
    int* antecessor;
    int* descoberta;
    int* termino;
    int tempo = 0;

    if(g != NULL)
        {
        rotulos    = (COR*) malloc(sizeof(int) * g->vertices);
        antecessor = (int*) malloc(sizeof(int) * g->vertices);
        descoberta = (int*) malloc(sizeof(int) * g->vertices);
        termino   = (int*) malloc(sizeof(int) * g->vertices);

        // Rotula todos vértices como Brancos:
        for(int i = 0 ; i < g->vertices; i++)
        {
            rotulos[i] = BRANCO;
            antecessor[i] = NULO;
        }
        
        subrotina_DFS(g, vertice, &tempo, rotulos, antecessor, descoberta, termino);

        for(int i = 0; i < g->vertices; i++)
        {
            if(rotulos[i] == BRANCO)
                subrotina_DFS(g, i, &tempo, rotulos, antecessor, descoberta, termino);
        }
    }
}

void grafo_deletar(GRAFO** g) // Apaga o grafo.
{
    if((*g) != NULL)
    {
        for(int i = 0; i < (*g)->vertices; i++) lista_apagar(&((*g) -> listas_de_adjascencia[i]));
        free((*g) -> listas_de_adjascencia);        
        free(*g);
        g = NULL;
    }
}