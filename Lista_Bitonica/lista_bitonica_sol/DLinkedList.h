#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <stdbool.h>

typedef struct dlinked_list TDLinkedList;

/**
 * @brief Instancia uma lista duplamente encadeada
 * 
 * @return TDLinkedList* lista instanciada
 */
TDLinkedList* TDLinkedList_create();
/**
 * @brief Insere um nó na lista duplamente encadeada, a partir do fim
 * 
 * @return _Bool 
 */
_Bool TDLinkedList_insert_end(TDLinkedList*, int);
/**
 * @brief Printa a lista duplamente encadeada
 * 
 * @return  
 */
void TDLinkedList_print(TDLinkedList*);
/**
 * @brief Reordena os nos da lista
 * 
 */
void TDLinkedList_sorted(TDLinkedList *);

#endif