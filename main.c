#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trabalho.h"

int main(){
    GRAFOL* grafo = NULL;

    grafo = fromFile();

    toFile(grafo);
    


}