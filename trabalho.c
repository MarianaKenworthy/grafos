#include <stdio.h>
#include <stdlib.h>
#include "trabalho.h"



void toFile (GRAFOL* grafo) {
    char filename[30];

    printf("onde deseja salvar o grafo?\n");
    scanf("%s\n", filename);

    FILE* output = fopen (filename, "w");
    NO aux;
    int vertAtual;
    
    char buffer[5];

    sprintf(buffer, "<%d><%d><%c><%d>\n", grafo->numvert, grafo->numares, grafo -> tipo, grafo->valorado);
    fwrite(buffer, sizeof(buffer), 1, output);

    for (int i=0; i <grafo->numvert; i++){
        aux = grafo->adjs[i];
        vertAtual = aux.vertice;
        while(aux.prox){
            fprintf(output, "<%d> <%d>", vertAtual, aux.prox->vertice);
            if(grafo->valorado == 1){
                fprintf(output, " <%d>\n", aux.peso);
            } else 
                fprintf(output, " \n", );
        }
    }

}