typedef struct no {
    int vertice;
    struct no* prox;
} NO;

typedef struct matriz {
    int vertice;
    struct matriz* prox;
    struct no* adjs;
} LISTA;

void fromFile;
void toFile;
LISTA* converteLista;
int* converteMatriz;
void calculaGrau;
void prettyPrint;
void geradoraMinima;
void dijkstra;
void buscaLength;
void buscaDepth;

