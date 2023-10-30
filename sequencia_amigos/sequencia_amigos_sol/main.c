#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int sum_of_divisors(int n) {
  int sum = 1;
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}

void find_and_print_amicable_pairs(int limit) {
  TLinkedList* list = TLinkedList_create();
  if (list == NULL) {
    exit(EXIT_FAILURE);
  }

  for (int i = 2; i < limit; ++i) {
    int sum1 = sum_of_divisors(i);
    if (sum1 < limit && sum1 > i) { 
      int sum2 = sum_of_divisors(sum1);
      if (sum2 == i) {
        TLinkedList_insert(list, i, sum1);
      }
    }
  }

  TLinkedList_print(list);
  TLinkedList_destroy(list);
}

int main() {
  int limit;
  scanf("%d", &limit);

  find_and_print_amicable_pairs(limit);
  return 0;
}
