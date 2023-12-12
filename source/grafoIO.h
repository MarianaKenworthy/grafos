typedef struct no {
    int vertice;
    int peso;
    struct no* prox;
} NO; 

typedef struct grafoL {
    int numvert;
    int numares;
    char tipo;
    int valorado;
    NO** adjs;
} GRAFOL;

typedef struct grafoM {
    int numvert;
    int numares;
    char tipo;
    int valorado;
    int ** adjs;
} GRAFOM;

GRAFOL* fromFile (); 
void toFile (GRAFOL* grafo);