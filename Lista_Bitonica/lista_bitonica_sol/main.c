#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TDLinkedList *lista = TDLinkedList_create();
    int num;
    char c = 0;

    while (c != '\n') {
        scanf("%d%c", &num, &c);
        TDLinkedList_insert_end(lista, num);
    }
    TDLinkedList_sorted(lista);
    TDLinkedList_print(lista);
}