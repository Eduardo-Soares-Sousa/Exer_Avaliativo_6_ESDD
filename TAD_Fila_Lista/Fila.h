#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE_FILA 10

typedef struct fila* Fila;
typedef int Element;

void inciar_fila(Fila* fila);

bool eh_cheia_fila(Fila fila);

bool eh_vazia_fila(Fila fila);

bool adiconar_fila(Fila fila, Element novo_elemento);

Element sai_da_Fila(Fila fila);