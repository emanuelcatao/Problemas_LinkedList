#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* prox;
}TNo;

typedef struct linked_list {
    TNo* inicio;
    TNo* fim;
} TLinkedList;

TNo* TNo_createNFill(int);

TLinkedList* TLinkedList_create(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if(nova!=NULL){
        nova->inicio = NULL;
        nova->fim = NULL;
    } return nova;
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

/**
 * @brief Função auxiliar para Permutate_List. Permuta os nós partindo de lista->inicio, alterando
 * as referencias de cada um deles, conforme a necessidade imposta pelo fator de permutação
 * 
 * @param lista_inicio ponteiro para o primeiro elemento da lista
 * @param numero fator de permutação
 * @return TNo* novo nó "chave" de um grupo de nós
 */
TNo* Permute_Nodes(TNo* lista_inicio, int numero){
    TNo *current = lista_inicio;
    int count = 0;
    
    // Conta os nós de cada grupo de permutação
    while (current != NULL && count < numero) {
        current = current->prox;
        count++;
    }
    
    /*
    Se não tiver nós para serem permutados (de forma que cont < numero) então retorna esse
    grupo sem alterações. Exemplo:
    
    ENTRADA:
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
        3
    
    Grupos de nós: (1 -> 2 -> 3) (4 -> 5 -> 6) (7 -> 8)
    Veja que o último grupo não está completo com os três nós necessários para a permuta,
    logos eles ficam inalterados.
    */ 
    if (count < numero) {
        return lista_inicio;
    }
    
    // Inverte os N primeiros nós (inverte os nós desse grupo que está sendo trabalhado)
    TNo *prev = NULL;
    current = lista_inicio;
    for (int i = 0; i < numero; i++) {
        TNo *prox = current->prox;
        current->prox = prev;
        prev = current;
        current = prox;
    }
    
    // Continua percorrendo os nós, invertendo-os grupo por grupo.
    lista_inicio->prox = Permute_Nodes(current, numero);
    
    // Retorna então o novo nó "cabeça" do grupo
    return prev;
}

void Permutate_List(TLinkedList* lista, int numero) {
    lista->inicio = Permute_Nodes(lista->inicio, numero);
}

int TLinkedList_print(TLinkedList* lista){
    TNo* aux = lista->inicio;
    int size = 0;
    while(aux->prox!=NULL){
        size++;
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    size++;
    printf("%d\n", aux->info);

    return size;
}

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