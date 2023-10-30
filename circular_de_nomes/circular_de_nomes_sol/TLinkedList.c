#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[100];
    struct no* prox;
} TNo;

struct linked_list {
    TNo* inicio;
    TNo* fim;
};

TLinkedList* TLinkedList_create() {
    TLinkedList* lista = (TLinkedList*)malloc(sizeof(TLinkedList));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

void TLinkedList_destroy(TLinkedList* lista) {
    TNo *p = lista->inicio, *q;
    while (p) {
        q = p;
        p = p->prox;
        free(q);
    }
    free(lista);
}

int TLinkedList_insert(TLinkedList* lista, const char* nome) {
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    if (!novo) return 0;
    strcpy(novo->nome, nome);
    if (!lista->inicio) {
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox = novo;
    } else {
        novo->prox = lista->inicio;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    return 1;
}

int TLinkedList_remove(TLinkedList* lista, const char* nome) {
    if (!lista->inicio) return 0;
    TNo *p = lista->inicio, *q = NULL;
    do {
        if (strcmp(p->nome, nome) == 0) {
            if (p == lista->inicio && p == lista->fim) {
                lista->inicio = lista->fim = NULL;
            } else {
                if (p == lista->inicio) lista->inicio = p->prox;
                if (p == lista->fim) lista->fim = q;
                q->prox = p->prox;
            }
            free(p);
            return 1;
        }
        q = p;
        p = p->prox;
    } while (p != lista->inicio);
    return 0;
}

void TLinkedList_print(TLinkedList* lista) {
    if (!lista->inicio) {
        printf("Lista vazia\n");
        return;
    }
    TNo* p = lista->inicio;
    do {
        printf("%s ", p->nome);
        p = p->prox;
    } while (p != lista->inicio);
    printf("\n");
}
