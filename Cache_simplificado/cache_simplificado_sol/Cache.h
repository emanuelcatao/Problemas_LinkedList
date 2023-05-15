#ifndef CACHE_H
#define CACHE_H

typedef struct cache Cache;

Cache* createCache(int);

int put(Cache*, int, int);

int get(Cache*, int);

void freeCache(Cache*);

#endif