#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "grafoIO.h"



GRAFOL* fromFile () { 
    char filename[30];
    printf("insira o nome do arquivo onde se encontra o grafo (incluir .txt): ");
    scanf("%s", filename);


    FILE* input = fopen(filename, "r");
    if(!input){
        printf("erro ao abrir o arquivo.\n");
        exit(1);
    }

    int numeros[3];
    char type;
    fscanf(input, "<%d><%d><%c><%d>", &numeros[0], &numeros[1], &type, &numeros[2]);
    fseek(input, 1, 1);
    GRAFOL* novoGrafo = malloc(sizeof(GRAFOL));
    novoGrafo->numvert =numeros[0];
    novoGrafo->numares = numeros[1];
    novoGrafo->tipo= type;
    novoGrafo->valorado=numeros[2];

    novoGrafo->adjs = malloc(sizeof(NO*)*(novoGrafo->numvert));

    for(int i = 0; i < novoGrafo->numvert; i++){
        novoGrafo->adjs[i] = malloc(sizeof(NO));
        novoGrafo->adjs[i]->vertice = i+1;
        novoGrafo->adjs[i]->prox = NULL;
    }


    int vertex, adjacent, weight;
    NO* atual, *antes;

    while (fscanf(input, "\n<%d><%d>", &vertex, &adjacent)== 2){
        if(vertex > novoGrafo->numvert || adjacent >novoGrafo->numvert){
            printf("documento invalido favor checar parametros\n");
            return NULL;
        }

        atual = novoGrafo->adjs[vertex-1];
            while(atual){
                antes = atual;
                atual=atual->prox;
            }
            if(atual==NULL){
                atual = malloc(sizeof(NO));
                atual->vertice = adjacent;
                fscanf(input, "<%d>", &weight);
                if(weight =='\n')
                    atual -> peso = 1;
                else {
                    atual -> peso = weight;
                    fseek(input, 1, 1);
                }
                atual -> prox = NULL;
                antes->prox = atual;
            }
        
        } 

    printf("grafo carregado com sucesso!\n");
    fclose(input);
    return novoGrafo;
    }

void toFile (GRAFOL* grafo) {

    if (grafo == NULL){
        printf("grafo invalido\n");
        return;
    }
    char filename[30];

    printf("onde deseja salvar o grafo?\n");
    scanf("%s", filename);

    FILE* output = fopen (filename, "w+");
    if(output == NULL){
        printf("erro ao abrir o arquivo.\n");
        exit(1);
    }

    NO* aux;
    int vertAtual;
    
    char buffer1[64];
    char buffer2[24];
    char buffer3[10];

    sprintf(buffer1, "<%d><%d><%c><%d>\n", grafo->numvert, grafo->numares, grafo -> tipo, grafo->valorado);
    fwrite(buffer1, strlen(buffer1), 1, output);

    for (int i=0; i <grafo->numvert; i++){
        aux = (grafo->adjs[i]);
        vertAtual = aux->vertice;
        while(aux->prox){
            sprintf(buffer2, "<%d><%d>",vertAtual, aux->prox->vertice);
            fwrite(buffer2, strlen(buffer2), 1, output);

            if(grafo->valorado == 1){
                sprintf(buffer3, "<%d>\n", aux->prox->peso);
                fwrite(buffer3, strlen(buffer3), 1, output);
 
            } else 
                fputc('\n', output);

            aux = aux->prox;
        }
    }

printf("grafo salvo com sucesso!\n");
fclose(output);
}