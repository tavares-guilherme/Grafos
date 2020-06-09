#ifndef GRAFO_H

    #define GRAFO_H
    
    typedef int COR;
    #define BRANCO 0
    #define CINZA  1
    #define PRETO  2
    #define NULO  -1
    typedef struct grafo_ GRAFO;



    GRAFO* grafo_criar(int n); // Cria um grafo com n vértices
    int    grafo_inserir_aresta(GRAFO* g, int no1, int no2); // Insere uma dada aresta.
    int    grafo_remover_aresta(GRAFO* g, int no1, int no2); // Remove uma dada aresta.
    void   grafo_imprimir(GRAFO* g); // Imprime a lista de adjascência.
    void   grafo_DFS(GRAFO* g, int vertice);
    void   grafo_deletar(GRAFO** g); // Apaga o grafo.

#endif