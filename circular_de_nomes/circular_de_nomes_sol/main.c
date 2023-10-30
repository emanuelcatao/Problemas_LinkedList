#include "TLinkedList.h"
#include <stdio.h>
#include <string.h>

int main() {
  TLinkedList* lista = TLinkedList_create();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char comando[10], nome[100];
    scanf("%s", comando);
    if (strcmp(comando, "add") == 0) {
      scanf("%s", nome);
      TLinkedList_insert(lista, nome);
    } else if (strcmp(comando, "remove") == 0) {
      scanf("%s", nome);
      if (!TLinkedList_remove(lista, nome)) {
        printf("Nome '%s' nao encontrado\n", nome);
      }
    } else if (strcmp(comando, "print") == 0) {
      TLinkedList_print(lista);
    }
  }
  TLinkedList_destroy(lista);
  return 0;
}
