#include <stdio.h>
#include <stdlib.h>
#include "trabalho.h"


void fromFile () {
    char filename[30];
    printf("insira o nome do arquivo onde se encontra o grafo (incluir .txt): ");
    scanf("%s", filename);

    FILE* input = fopen(filename, "r");
    if(!input){
        printf("erro ao abrir o arquivo.\n");
        exit(1);
    }

    int buffer[4];
    fscanf(input, "<%d><%d><%c><%d>\n", buffer);
    GRAFOL* novoGrafo = malloc(sizeof(GRAFOL));
    novoGrafo->numvert =buffer[0];
    novoGrafo->numares = buffer[1];
    novoGrafo->tipo= buffer[2];
    novoGrafo->valorado=buffer[3];

    novoGrafo->adjs = malloc(sizeof(NO)*(novoGrafo->numvert));

    for(int i = 0; i < novoGrafo->numvert; i++){
       novoGrafo->(adjs[i])->vertice = i+1;
       novoGrafo->adjs[i]->prox = NULL;
    }

    int aux[3];
    NO* atual;
    fscanf(consome uma linha);

    while (não chega no fim){
        atual = novoGrafo->adjs[aux[0]]->prox;
        if(atual== NULL){
            atual = malloc(sizeof(NO));
            atual ->vertice = aux[1];
            if(aux[2] = '\n');
                atual -> peso = 1;
            else {
                atual -> peso = aux[2];
                fseek(input, 1, 1);
            }
            atual -> prox = NULL;
            novoGrafo->adjs[aux[0]]->prox = atual;
            fscanf(consome uma linha);
        } else {
            atual = atual->prox;
        }   
    }
}

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

GRAFOL* toLista (GRAFOM* matriz){

    GRAFOL* retorno = malloc(sizeof(GRAFOL));
    retorno->numvert = matriz->numvert;
    retorno->numares = matriz->numares;
    retorno->tipo = matriz->tipo;
    retorno->valorado = matriz->valorado;
    retorno->adjs = malloc(sizeof(NO)*(retorno->numvert));

    NO* aux;
    for(int i=0; i<matriz->numvert;i++){
        aux = retorno->adjs[i]->prox;
        //falta pedaço aqui
        for(int j=0; j<matriz->numvert;j++){
            if(matriz->adjs[i][j]!=0){
                aux=malloc(sizeof(NO));
                aux->vertice = j;
                aux->peso= matriz->adjs[i][j];
                aux->prox = NULL;
                aux = aux->prox;
            }


        
        }

    }

}

void calculaGrau (GRAFOL* grafo){
    int contador = 0;
    NO* aux
    for(int i = 0; i <grafo->numvert; i++){
        printf("vertice %d tem grau ", grafo->adjs[i]->vertice);
        aux = grafo->adjs[i]->prox;

        if(aux){
            contador++;
            aux = aux->prox;
        } else {
            printf("%d\n", contador);
            continue;
        }
    }
}