#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

typedef struct linked_list TLinkedList;

TLinkedList* TLinkedList_create();
void TLinkedList_destroy(TLinkedList*);
int TLinkedList_insert(TLinkedList*, const char*);
int TLinkedList_remove(TLinkedList*, const char*);
void TLinkedList_print(TLinkedList*);

#endif
