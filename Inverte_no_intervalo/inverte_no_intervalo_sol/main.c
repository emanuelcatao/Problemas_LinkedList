#include "TLinkedList.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    int number;
    char proxChar;
    TLinkedList* solution = TLinkedList_create();
    while(scanf("%d%c", &number, &proxChar) == 2) { 
        TLinkedList_insert_end(solution, number);
        if(proxChar == '\n') break; 
    }

    int permutation;
    scanf("%d", &permutation);

    Permutate_List(solution, permutation);

    TLinkedList_print(solution);

    return 0;
}