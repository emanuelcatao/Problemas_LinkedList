#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no* prox;
    struct no* ant;
}TNo;

struct dlinked_list{
    TNo *inicio, *fim;
};

//auxiliar
TNo* TNo_createNFill(int);

TDLinkedList* TDLinkedList_create(){
    TDLinkedList* nova = malloc(sizeof(TDLinkedList));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
    } return nova;
}

_Bool TDLinkedList_insert_end(TDLinkedList* lista, int info){
    TNo* novo = TNo_createNFill(info);
    if(novo==NULL) return false;
    
    lista->inicio = (lista->inicio == NULL) ? novo : lista->inicio;
    if(lista->fim != NULL)
      lista->fim->prox = novo; 

    novo->ant = lista->fim;
    lista->fim = novo;
    return true;
}

_Bool TDLinkedList_remove_from_begin(TDLinkedList* lista){
    if(lista->inicio == NULL) return false;

    lista->inicio = lista->inicio->prox;
    lista->inicio->ant = NULL;

    return true;
}

_Bool TDLinkedList_remove_from_end(TDLinkedList* lista){
    if(lista->fim == NULL) return false;

    lista->fim = lista->fim->ant;
    lista->fim->prox = NULL;

    return true;
}

void TDLinkedList_print(TDLinkedList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("<- %d ->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

void TDLinkedList_destroy(TDLinkedList* lista){
    TNo* node = lista->inicio;
    while (node != NULL) {
        TNo* temp = node->prox;
        free(node);
        node = temp;
    }
    free(lista);
}

TNo* sort(TDLinkedList *lista) {
    if (lista->inicio == NULL || lista->inicio->prox == NULL) {
        return lista->inicio;
    }     

    TNo* primeiro = lista->inicio;
    TNo* ultimo = lista->fim;

    TNo* resultado = malloc(sizeof(TNo));
    if(resultado!=NULL){
        resultado->info = 0;
        resultado->prox = NULL;
        resultado->ant = NULL;
    }
    
    TNo* resultadoEnd = resultado;

    while (primeiro != ultimo) {
        if (ultimo->info <= primeiro->info) {
            TNo* aux = ultimo->ant;
            resultadoEnd->prox = ultimo;
            ultimo->ant->prox = NULL;
            ultimo->ant = resultadoEnd;
            ultimo = aux;
            resultadoEnd = resultadoEnd->prox;
        } else {
            TNo* aux = primeiro->prox;
            resultadoEnd->prox = primeiro;
            primeiro->prox->ant = NULL;
            primeiro->ant = resultadoEnd;
            primeiro = aux;
            resultadoEnd = resultadoEnd->prox;
        }
    }
    
    resultadoEnd->prox = primeiro;
    primeiro->ant = resultadoEnd;
    resultado->prox->ant = NULL;
 
    return resultado->prox;
}

void TDLinkedList_sorted(TDLinkedList *lista) {
    lista->inicio = sort(lista);
    TNo *aux = lista->inicio;
    while(aux->prox != NULL)
        aux = aux->prox;
    lista->fim = aux;
}

//Auxiliar
TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = NULL;
        novo->ant = NULL;
    } return novo;
}



