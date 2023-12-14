#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE_FILA 20

typedef struct node* Node;
typedef struct fila* Fila;

typedef Paciente Element;

void iniciar_fila(Fila* fila);

bool eh_cheia_fila(Fila fila);

bool eh_vazia_fila(Fila fila);

bool adicionar_fila(Fila fila, Element novo_elemento);

Element sai_da_fila(Fila fila);

void inserir_na_fila_prioritaria(Fila fila, Paciente novo_elemento);