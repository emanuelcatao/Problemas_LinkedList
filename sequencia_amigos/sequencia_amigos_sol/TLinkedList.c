#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num1, num2;
    struct no* prox;
} TNo;

TNo* TNo_createNFill(int, int);

struct linked_list {
    TNo* inicio;
};

TLinkedList* TLinkedList_create() {
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if (nova != NULL) {
        nova->inicio = NULL;
    }
    return nova;
}

bool TLinkedList_insert(TLinkedList* lista, int num1, int num2) {
    TNo* novo = TNo_createNFill(num1, num2);
    if (novo == NULL) return false;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        novo->prox = novo;
    } else {
        TNo* aux = lista->inicio;
        while (aux->prox != lista->inicio) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = lista->inicio;
    }
    return true;
}

void TLinkedList_print(TLinkedList* lista) {
    if (lista->inicio == NULL) return;

    TNo* aux = lista->inicio;
    do {
        printf("(%d, %d) ", aux->num1, aux->num2);
        aux = aux->prox;
    } while (aux != lista->inicio);
    printf("\n");
}

TNo* TNo_createNFill(int num1, int num2) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->num1 = num1;
        novo->num2 = num2;
        novo->prox = NULL;
    }
    return novo;
}

void TLinkedList_destroy(TLinkedList* lista) {
    if (lista->inicio == NULL) {
        free(lista);
        return;
    }

    TNo *aux = lista->inicio->prox, *aux2;
    while (aux != lista->inicio) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(lista->inicio);
    free(lista);
}
