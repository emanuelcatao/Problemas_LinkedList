#ifndef TLINKED_LIST_H
#define TLINKED_LIST_H
#include <stdbool.h>

typedef struct linked_list TLinkedList;

TLinkedList* TLinkedList_create();
void TLinkedList_destroy(TLinkedList*);
bool TLinkedList_insert(TLinkedList*, int, int);
void TLinkedList_print(TLinkedList*);


#endif
