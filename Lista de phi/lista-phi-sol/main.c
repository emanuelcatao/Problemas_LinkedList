#include "TLinkedList.h"
#include <stdio.h>

TLinkedList* IntegerDisassembler(int number){
  TLinkedList* list = TLinkedList_create();
  while(number){
    TLinkedList_insert_begin(list, number % 10);
    number /= 10;
  }
  return list;
}

int main(){
  int input;
  scanf("%d",&input);
  TLinkedList* solution = TLinkedList_create(), *temp;
  TLinkedList_insert_end(solution, input);
  do{
    TLinkedList* temp = IntegerDisassembler(input);
    input = TLinkedList_FromSquares(temp);
    TLinkedList_destroy(temp);
    TLinkedList_insert_end(solution, input);
  }while(input>=10);
  TLinkedList_print(solution);
  printf("%s\n", (TLinkedList_getFim(solution)==1) ? "bacana" : "non-bacana");
  return 0;
}