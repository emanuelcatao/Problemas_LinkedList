#include "Cache.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int key, value, index = 0;
    int* saida = (int*)malloc(100*sizeof(int));
    char linha[100];
    scanf("Cache %d", &value);
    Cache* cache = createCache(value);
    
    char command;
    while (1) {
        command = getchar();
        if (command == '0') {
            break;
        } else if (command == 'p') {
            scanf("%*s %d %d", &key, &value);
            saida[index] = put(cache, key, value);
            index++;
        } else if (command == 'g') {
            scanf("%*s %d", &key);
            saida[index] = get(cache, key);
            index++;
        }
    }
    printf("[");
    for(int i = 0; i < index - 1; i++) {
        printf("%d, ", saida[i]);
    }
    printf("%d]\n", saida[index-1]);

    freeCache(cache);
    free(saida);

    return 0;
}