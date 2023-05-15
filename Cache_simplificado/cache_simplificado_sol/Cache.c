#include "Cache.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* ant;
    struct Node* prox;
} Node;

struct cache {
    int size;
    int MAX_CACHE_SIZE;
    Node* inicio;
    Node* fim;
};

Cache* createCache(int size) {
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    cache->size = 0;
    cache->MAX_CACHE_SIZE = size;
    cache->inicio = NULL;
    cache->fim = NULL;
    return cache;
}

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->ant = NULL;
    node->prox = NULL;
    return node;
}

int cacheInsertInicio(Cache* cache, Node* node){
    cache->inicio = (cache->inicio == NULL) ? node : cache->inicio;
    if(cache->fim != NULL) {
      cache->fim->prox = node;
    }
    node->ant = cache->fim;
    cache->fim = node;
    cache->size++;
    return 1;
}

int cacheDeleteFromBegin(Cache* cache){
    if(cache->inicio == NULL) return 0;

    Node* temp = cache->inicio;
    cache->inicio = cache->inicio->prox;
    cache->inicio->ant = NULL;
    free(temp);
    return 1;
}

void updateCache(Cache* cache, Node* node) {
    if (node != cache->fim) {
        if (node == cache->inicio) {
            cache->inicio = node->prox;
            cache->inicio->ant = NULL;
        } else {
            node->ant->prox = node->prox;
            node->prox->ant = node->ant;
        }

        node->ant = cache->fim;
        cache->fim->prox = node;
        cache->fim = node;
        node->prox = NULL;
    }
}

int put(Cache* cache, int key, int value) {
    Node* node = cache->inicio;
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            updateCache(cache, node);
            return 200;
        }
        node = node->prox;
    }

    Node* newNode = createNode(key, value);
    cacheInsertInicio(cache, newNode);
    if (cache->size > cache->MAX_CACHE_SIZE) {
        cacheDeleteFromBegin(cache);
    }
    return 200;
}

int get(Cache* cache, int key) {
    Node* node = cache->inicio;
    while (node != NULL) {
        if (node->key == key) {
            updateCache(cache, node);
            return node->value;
        }
        node = node->prox;
    }
    return -1; 
}

void freeCache(Cache* cache) {
    Node* node = cache->inicio;
    while (node != NULL) {
        Node* temp = node->prox;
        free(node);
        node = temp;
    }
    free(cache);
}

