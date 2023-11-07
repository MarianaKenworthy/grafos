#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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

    int numeros[3];
    char type;
    fscanf(input, "%d%d%c%d", &numeros[0], &numeros[1], &type, &numeros[2]);
    fseek(input, 1, 1);
    GRAFOL* novoGrafo = malloc(sizeof(GRAFOL));
    novoGrafo->numvert =numeros[0];
    novoGrafo->numares = numeros[1];
    novoGrafo->tipo= type;
    novoGrafo->valorado=numeros[2];

    novoGrafo->adjs = malloc(sizeof(NO)*(novoGrafo->numvert));

    for(int i = 0; i < novoGrafo->numvert; i++){
       novoGrafo->adjs[i]->vertice = i+1;
       novoGrafo->adjs[i]->prox = NULL;
    }

    int aux[3];
    NO* atual;

    while (fscanf(input, "%d%d%d", &aux[0], &aux[1], &aux[2])){
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
    
    char buffer[sizeof(int)*5];

    sprintf(buffer, "%d%d%d%d\n", grafo->numvert, grafo->numares, grafo -> tipo, grafo->valorado);
    fwrite(buffer, sizeof(buffer), 1, output);

    for (int i=0; i <grafo->numvert; i++){
        aux = *(grafo->adjs[i]);
        vertAtual = aux.vertice;
        while(aux.prox){
            fprintf(output, "%d%d", vertAtual, aux.prox->vertice);
            if(grafo->valorado == 1){
                fprintf(output, "%d\n", aux.peso);
            } else 
                fputc('\n', output);
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
        aux = retorno->adjs[i];
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
    GRAFOM* retorno;

    retorno->numvert = lista->numvert;
    retorno-> numares = lista->numares;
    retorno-> tipo = lista->tipo;
    retorno->valorado = lista->valorado;

    retorno->adjs = malloc(sizeof(int*)*(lista->numvert));
    if(retorno->adjs){
        for(int i=0;i<lista->numvert; i++){
            retorno->adjs[i] = malloc(sizeof(int)*(lista->numvert));
            if(retorno->adjs[i]){
                for(int j =0; j<lista->numvert;j++)
                    retorno->adjs[i][j]=0;
            }
        }
    }

    NO* aux;
    for(int i = 0; i<lista->numvert;i++){
        aux = lista->adjs[i]->prox;
        while(aux){
            retorno->adjs[i][(aux->vertice) - 1] = aux->peso;
            aux=aux->prox;
        }
    }

    return retorno;
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

int chaveMin(int* key, int* arvoreMin, int numvert){
    int min = INT_MAX, minimo;

    for(int i=0;i<numvert;i++){
        if(arvoreMin[i] == -1 && key[i] < min){
            min= key[i];
            minimo = i;     
        }
    }
    return minimo;
}

void prim(GRAFOL* grafo, int vertFonte, int* arvoreMin){
    int key[grafo->numvert];

    for(int i=0;i<grafo->numvert;i++){
        key[i]=INT_MAX;
        arvoreMin[i]=-1;
    }

    key[vertFonte]=0;
    int atual;
    NO* adj;

    for(int i=0;i<grafo->numvert-1;i++){
        atual = chaveMin(key, arvoreMin, grafo->numvert);
        adj=grafo->adjs[atual]->prox;

        while(adj){
            if(adj->peso < key[adj->vertice]){
                arvoreMin[adj->vertice] = atual;
                key[adj->vertice] = adj->peso;
            }
            adj=adj->prox;
        }
    }   
}

int distanciaMinima(int* distancia, bool*caminhoMinimo, int numvert){
    int minimo = INT_MAX, distMin;

    for(int i=0;i<numvert;i++){
        if(caminhoMinimo[i]==false && distancia[i] < minimo){
            minimo = distancia[i];
            distMin = i;
        }
    }
    return distMin;
}

void relaxa(int atual, int adj, int peso, int*distancia, bool*caminhoMin){
    if(distancia[adj] > distancia[atual] + peso){
        distancia[adj] = distancia[atual] + peso;
        caminhoMin[adj] = atual;
    }
}

void dijkstra (GRAFOL* grafo, int vertFonte, bool* caminhoMin, int* distancia){

    for(int i=0;i<grafo->numvert;i++){
        distancia[i] = INT_MAX;
        caminhoMin[i]=false;
    }
    distancia[vertFonte]=0;
    int atual;
    NO* adj;

   for(int i=0; i<grafo->numvert - 1;i++){
        atual = distanciaMinima(distancia, caminhoMin, grafo->numvert);
        caminhoMin[atual] = true;

        adj = grafo->adjs[atual]->prox;
        while(adj){
            relaxa(atual, adj->vertice, adj->peso, distancia, caminhoMin);
            adj = adj->prox;
        }
   }
}

void buscaBreadth (GRAFOL* grafo, int vertFonte, int* distancia){
    int cor[grafo->numvert];
    int pai[grafo->numvert];

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
}

void buscaDepth(GRAFOL* grafo, int* descoberta, int*finalizacao, int* pai){
    int tempo = 0;
    int cor[grafo->numvert];
    
    for(int i=0;i<grafo->numvert;i++){
        cor[i]=0;
        pai[i]=0;
    }

    for(int i=0;i<grafo->numvert;i++){
        if(cor[i]==0)
            visitaDepth(grafo, i, cor, descoberta, finalizacao, pai, &tempo);
    }
}

void visitaDepth(GRAFOL* grafo, int i, int* cor, int*descoberta, int*finalizacao, int*pai, int*tempo){
    cor[i]=1;
    (*tempo)= (*tempo)+1;
    descoberta[i] = (*tempo);
    printf("%d ", i);
    NO* adj = grafo->adjs[i]->prox;

    while(adj){
        if(cor[adj->vertice]==0){
            pai[adj->vertice]=i;
            visitaDepth(grafo, adj->vertice, cor, descoberta, finalizacao, pai, tempo);
        }
    }
    cor[i] = 2;
    (*tempo) = (*tempo)+1;
    finalizacao[i]= (*tempo);
}