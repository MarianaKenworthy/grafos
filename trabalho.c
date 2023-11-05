#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trabalho.h"


GRAFOL* fromFile () {
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
       novoGrafo->adjs[i]->vertice = i+1;
       novoGrafo->adjs[i]->prox = NULL;
    }

    int aux[3];
    NO* atual;

    while (fscanf(input, "<%d><%d><%d>", aux)){
        atual = novoGrafo->adjs[aux[0]]->prox;
        if(atual== NULL){
            atual = malloc(sizeof(NO));
            atual ->vertice = aux[1];
            if(aux[2] = '\n')
                atual -> peso = 1;
            else {
                atual -> peso = aux[2];
                fseek(input, 1, 1);
            }
            atual -> prox = NULL;
            novoGrafo->adjs[aux[0]]->prox = atual;
        } else 
            atual = atual->prox;
         
    }
    printf("grafo carregado com sucesso!\n");
    fclose(input);
    return novoGrafo;
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
        aux = *(grafo->adjs[i]);
        vertAtual = aux.vertice;
        while(aux.prox){
            fprintf(output, "<%d> <%d>", vertAtual, aux.prox->vertice);
            if(grafo->valorado == 1){
                fprintf(output, "<%d>\n", aux.peso);
            } else 
                fprintf(output, "\n", NULL);
        }
    }

printf("grafo salvo com sucesso!\n");
fclose(output);
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
        aux = &(retorno->adjs[i]);
        aux = malloc(sizeof(NO));
        aux->vertice = i+1;
        aux->prox = NULL;
        aux->peso = 0;
        retorno -> adjs[i] = aux;
        aux = aux->prox;

        for(int j=0; j<matriz->numvert;j++){
            if(matriz->adjs[i][j]!=0){
                aux = malloc(sizeof(NO));
                aux -> vertice = j+1;
                aux -> peso = matriz->adjs[i][j];
                aux -> prox = NULL;
                aux = aux->prox;
            }
        }
    }
    return retorno;
}

GRAFOM* toMatriz (GRAFOL* lista){
    
}

void calculaGrau (GRAFOL *grafo){
    int contador = 0;
    NO* aux;
    for(int i = 0; i <grafo->numvert; i++){
        printf("vertice %d tem grau ", grafo->adjs[i]->vertice);
        aux = (grafo->adjs[i]->prox);

        if(aux){
            contador++;
            aux = aux->prox;
        } else {
            printf("%d\n", contador);
            continue;
        }
    }
}

int* buscaBreadth (GRAFOL* grafo, int vertFonte){
    int cor[grafo->numvert];
    int pai[grafo->numvert];
    int distancia[grafo->numvert];

    for(int i=0;i<grafo->numvert;i++){
        cor[i]=0;
        distancia[i] = 1000000;
        pai[i]=0;
    }

    cor[vertFonte]=1;
    distancia[vertFonte]=0;
    pai[vertFonte]=0;

    int fila[grafo->numvert];
    int inicio=0, fim=0;
    int atual;
    NO*adj;

    fila[fim]= vertFonte;
    fim++;

    while(fim != inicio){
        atual = fila[inicio++];
        printf("%d ", atual);
        adj = grafo->adjs[atual]->prox;
        while(adj){
            if(cor[adj->vertice]==0){
                cor[adj->vertice]=1;
                distancia[adj->vertice]= distancia[atual]+1;
                pai[adj->vertice]=atual;
                fila[fim++] = adj->vertice;
            }
            adj=adj->prox; 
        }
    cor[atual]=2;
    }
    return distancia;
}
