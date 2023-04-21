#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* prox;
}TNo;

TNo* TNo_createNFill(int);

struct linked_list{
    TNo* inicio;
    TNo* fim;
};
TLinkedList* TLinkedList_create(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
    } return nova;
}
_Bool TLinkedList_insert_begin(TLinkedList* lista, int info){
    TNo* novo = TNo_createNFill(info);
    if(novo==NULL) return false;
    
    if(lista->inicio != NULL)
        novo->prox = lista->inicio;
    lista->inicio = novo;
    if(lista->fim == NULL)
      lista->fim = novo;
    return true;
}

_Bool TLinkedList_insert_end(TLinkedList* lista, int info){
    TNo* novo = TNo_createNFill(info);
    if(novo==NULL) return false;
    
    lista->inicio = (lista->inicio == NULL) ? novo : lista->inicio;
    if(lista->fim != NULL)
      lista->fim->prox = novo; 

    lista->fim = novo;
    return true;
}
void TLinkedList_print(TLinkedList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

//Auxiliares

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = NULL;
    } return novo;
}

void TLinkedList_destroy(TLinkedList* lista){
    TNo* aux = lista->inicio, *aux2;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}
int TLinkedList_FromSquares(TLinkedList* lista){
    TNo* aux = lista->inicio;
    int result = 0;
    while(aux!=NULL){
        result += (aux->info)*(aux->info);
        aux = aux->prox;
    }
    return result;
}

int TLinkedList_getFim(TLinkedList* lista){
  return lista->fim->info;
}