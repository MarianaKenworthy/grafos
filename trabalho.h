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

GRAFOL* fromFile (); //feito
void toFile (GRAFOL* grafo); //feito
GRAFOL* toLista (GRAFOM* matriz); //feito
GRAFOM* toMatriz;
void calculaGrau (GRAFOL* grafo); //feito
void geradoraMinima;
void dijkstra;
int* buscaBreadth (GRAFOL* grafo, int vertFonte)//feito
void buscaDepth;

