#include "TCycleList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int* perm = malloc(n * sizeof(int));
  if (perm == NULL) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", &perm[i]);
    if (perm[i] < 1 || perm[i] > n) {
      free(perm);
      return EXIT_FAILURE;
    }
  }

  TCycleList* cycles = TCycleList_create();
  if (cycles == NULL) {
    free(perm);
    return EXIT_FAILURE;
  }

  bool* visited = calloc(n, sizeof(bool));
  if (visited == NULL) {
    TCycleList_destroy(cycles);
    free(perm);
    return EXIT_FAILURE;
  }

  printf("Ciclos da permutacao:\n");
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int current = i;
      do {
        printf("%d ", current + 1);
        visited[current] = true;
        current = perm[current] - 1;
      } while (current != i);
      printf("\n");
    }
  }

  TCycleList_destroy(cycles);
  free(visited);
  free(perm);

  return EXIT_SUCCESS;
}
