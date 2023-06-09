#ifndef TLINKED_LIST_H
#define TLINKED_LIST_H
#include <stdbool.h>

typedef struct linked_list TLinkedList;

/**
 * Cria uma uma instância válida de TLinkedList
 * @return TLinkedList*
 * */
TLinkedList* TLinkedList_create();
/**
 * Deleta apropriadamente uma uma instância válida de TLinkedList
 * @param TLinkedList* ponteiro para uma lista válida
 *  */
void TLinkedList_destroy(TLinkedList*);
/**
 * Insere um inteiro no início da lista.
 * @param TLinkedList* ponteiro da lista
 * @param int informação a ser inserida
 * @return _Bool (se deu certo ou não)
 * */
_Bool TLinkedList_insert_begin(TLinkedList*, int);
/**
 * Insere um inteiro no fim da lista.
 * @param TLinkedList* ponteiro da lista
 * @param int informação a ser inserida
 * @return _Bool (se deu certo ou não)
 * */
_Bool TLinkedList_insert_end(TLinkedList*, int);
/**
 * @brief Permuta os nós da lista, alterando seu ponteiro de inicío.
 * 
 * @param lista ponteiro da lista a ser permutada
 * @param numero fator de permutação
 */
void Permutate_List(TLinkedList*, int);

/**
 * Imprime uma lista 
 * @param TLinkedList* ponteiro para uma lista válida
 * @return int referente ao número de nós da lista
 *  */
int TLinkedList_print(TLinkedList*);


#endif