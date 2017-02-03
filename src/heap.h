#ifndef HEAP_H
#define HEAP_H

typedef int (*heap_pred)(int a, int b);

typedef struct {
    int size;
    long int *keys;
    heap_pred predicate;
} Heap;


int heap_pred_min(int a, int b);
int heap_pred_max(int a, int b);

Heap* heap_alloc(int size, heap_pred predicate);
void heap_free(Heap **h);
int heap_size(Heap *h);
void heapify(Heap *h, int index);
Heap* heap_build(long int *array, int size, heap_pred predicate);
void heap_push(Heap *h, long int key);
int heap_pop(Heap *h, long int *value);

#endif //HEAP_H
