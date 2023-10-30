#include "TCycleList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no* next;
} TNo;

TNo* TNo_create(int value) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->value = value;
        novo->next = NULL;
    }
    return novo;
}

struct cycle_list {
    TNo* first;
    TNo* last;
};

TCycleList* TCycleList_create() {
    TCycleList* list = malloc(sizeof(TCycleList));
    if (list != NULL) {
        list->first = NULL;
        list->last = NULL;
    }
    return list;
}

bool TCycleList_insert(TCycleList* list, int value) {
    TNo* novo = TNo_create(value);
    if (novo == NULL) return false;

    if (list->first == NULL) {
        list->first = novo;
        list->last = novo;
        novo->next = novo; 
    } else {
        list->last->next = novo;
        list->last = novo;
        novo->next = list->first; 
    }
    return true;
}

void TCycleList_print(TCycleList* list) {
    if (list->first == NULL) return;

    TNo* aux = list->first;
    do {
        printf("%d ", aux->value);
        aux = aux->next;
    } while (aux != list->first);
    printf("\n");
}

bool TCycleList_find_and_remove(TCycleList* list, int value) {
    if (list->first == NULL) return false;

    TNo* aux = list->first;
    TNo* prev = NULL;
    do {
        if (aux->value == value) {
            if (prev != NULL) {
                prev->next = aux->next;
            }
            if (aux == list->first) { 
                list->first = aux->next;
                if (list->first == aux) { 
                    list->first = NULL;
                }
            }
            if (aux == list->last) { 
                list->last = prev;
            }
            free(aux);
            return true;
        }
        prev = aux;
        aux = aux->next;
    } while (aux != list->first);

    return false;
}

void TCycleList_destroy(TCycleList* list) {
    if (list->first == NULL) {
        free(list);
        return;
    }

    TNo *aux = list->first->next, *next;
    while (aux != list->first) {
        next = aux->next;
        free(aux);
        aux = next;
    }
    free(list->first);
    free(list);
}
