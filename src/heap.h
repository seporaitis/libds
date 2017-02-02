#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int size;
    long int *keys;
} Heap;

Heap* heap_alloc(const int size);
void heap_free(Heap *h);
int heap_size(Heap *h);

#endif //HEAP_H
