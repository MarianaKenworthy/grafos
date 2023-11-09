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
GRAFOL* toLista (GRAFOM* matriz);
GRAFOM* toMatriz (GRAFOL* lista); 
int calculaGrau (GRAFOM *grafo, int vertice); 
int chaveMin(int* key, int *arvoreMin, int numvert);
void prim(GRAFOL* grafo, int vertFonte, int* arvoreMin); 
int distanciaMinima(int* distancia, bool*caminhoMinimo, int numvert);
void relaxa(int atual, int adj, int peso, int*distancia, bool*caminhoMin);
void dijkstra (GRAFOL* grafo, int vertFonte, bool* caminhoMin, int* distancia);
void buscaBreadth (GRAFOL* grafo, int vertFonte, int* distancia); 
void buscaDepth(GRAFOL* grafo, int* descoberta, int*finalizacao, int* pai); 
void visitaDepth(GRAFOL* grafo, int i, int* cor, int*descoberta, int*finalizacao, int*pai, int*tempo);

