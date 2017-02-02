#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


Heap* heap_alloc(const int size) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = size;
    h->keys = (long int*)malloc(size * sizeof(long int));

    return h;
}

void heap_free(Heap *h) {
    free(h);
    h = NULL;
}

int heap_size(Heap *h) {
    return h->size;
}
