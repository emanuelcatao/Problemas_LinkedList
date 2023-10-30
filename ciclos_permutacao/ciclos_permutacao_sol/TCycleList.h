#ifndef TCYCLE_LIST_H
#define TCYCLE_LIST_H

#include <stdbool.h>

typedef struct cycle_list TCycleList;

TCycleList* TCycleList_create();
void TCycleList_destroy(TCycleList*);
bool TCycleList_insert(TCycleList*, int);
void TCycleList_print(TCycleList*);
bool TCycleList_find_and_remove(TCycleList*, int);

#endif
