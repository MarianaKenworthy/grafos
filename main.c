#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "trabalho.h"
 
int main(){
    GRAFOL* grafoLista = NULL;

    grafoLista = fromFile();
 
    toFile(grafoLista);

    printf("Segue a matriz de adjacencias do grafo:\n");
    GRAFOM* grafoMatriz = toMatriz(grafoLista);
    
    printf("\nSegue a lista de adjacencias do grafo:\n");
    grafoLista = toLista(grafoMatriz);

    printf("\nSegue o grau do vertice 3:\n");
    int grau=calculaGrau(grafoMatriz, 3);
    printf("%d\n", grau);

    int arvore[grafoLista->numvert];
    printf("Segue a arvore geradora minimo por alg de Prim (impressa em forma de array):\n)");
    prim(grafoLista, 3,arvore);
    for(int i =0;i<grafoLista->numvert;i++)
        printf("%d ", arvore[i]);

    bool caminho[grafoLista->numvert];
    int distancia[grafoLista->numvert];
    printf("\nSegue o menor caminho do grafo a partir do vertice 2:\n");
    dijkstra(grafoLista, 2, caminho, distancia);
    for(int i = 1; i<grafoLista->numvert; i++)
        printf("%d ", distancia[i]);


    printf("\nSegue o grafo impresso conforme a busca de largura: \n");
    buscaBreadth(grafoLista, 3, distancia);

    int descoberta[grafoLista->numvert];
    int finalizacao[grafoLista->numvert];
    int pai[grafoLista->numvert];
    printf("\nSegue o grafo impresso conforme a busca de profundidade: \n");
    buscaDepth(grafoLista, descoberta, finalizacao, pai);
    for(int i = 1; i<grafoLista->numvert; i++){
        printf("%d ", descoberta[i]);
        printf("%d ", finalizacao[i]);
        printf("%d ", pai[i]);
    }
}