#include "Fila.h"
#include "Paciente.h"
#include "Pilha.h"

typedef struct node* Node;

struct node{
    Element info;
    Node next;
    Node prev;
};

struct fila{
    Node inicio;
    Node fim;
};

void iniciar_fila(Fila* fila){
    *fila = malloc(sizeof(struct fila));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}

bool eh_cheia_fila(Fila fila) {
    return false;
}

bool eh_vazia_fila(Fila fila) {
    return fila->inicio == NULL;
}

bool adicionar_fila(Fila fila, Element novo_elemento) {
    Node new_Node = malloc(sizeof(struct node));

    if (new_Node == NULL) {
        return false;
    }

    new_Node->info = novo_elemento;
    new_Node->next = NULL;

    if (eh_vazia_fila(fila)) {
        fila->inicio = new_Node;
    } else {
        fila->fim->next = new_Node;
    }

    fila->fim = new_Node;

    return true;
}

Element sai_da_fila(Fila fila) {
    if (eh_vazia_fila(fila)) {
        return -1;
    }

    Node first_node = fila->inicio;
    Element elemento = first_node->info;

    fila->inicio = first_node->next;
    free(first_node);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return elemento;
}

void inserir_na_fila_prioritaria(Fila fila, (Paciente) novo_elemento) {
    if (eh_vazia_fila(fila)) {
        adicionar_fila(fila, novo_elemento);
        return;
    }

    Node novo_node = malloc(sizeof(struct node));
    novo_node->info = novo_elemento;
    novo_node->next = NULL;

    Node anterior = NULL;
    Node atual = fila->inicio;

    while (atual != NULL && ((Paciente)novo_elemento)->prioridade > ((Paciente)atual->info)->prioridade) {
        anterior = atual;
        atual = atual->next;
    }

    if (anterior == NULL) {
        novo_node->next = fila->inicio;
        fila->inicio = novo_node;
    } else {
        anterior->next = novo_node;
        novo_node->next = atual;
    }

    if (atual == NULL) {
        fila->fim = novo_node;
    }
}