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
GRAFOM* toMatriz (GRAFOL* lista); //feito
void calculaGrau (GRAFOL* grafo); //feito
int chaveMin(int* key, bool*arvoreMin, int numvert)
int* prim(GRAFOL* grafo, int vertFonte); //feito conferir retorno
int distanciaMinima(int* distancia, bool*caminhoMinimo, int numvert);
void relaxa(int atual, int adj, int peso, int*distancia, bool*caminhoMin);
void dijkstra (GRAFOL* grafo, int vertFonte); //feito rever retorno
int* buscaBreadth (GRAFOL* grafo, int vertFonte); //feito rever retorno
void buscaDepth(GRAFOL* grafo); //feito falta retorno
void visitaDepth(GRAFOL* grafo, int i, int* cor, int*distancia, int*finalizacao, int*pai, int*tempo);

