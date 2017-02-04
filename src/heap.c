#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"


int heap_pred_min(int a, int b) {
    if (a == b) {
        return 0;
    } else if (a < b) {
        return 1;
    } else {
        return -1;
    }
}

int heap_pred_max(int a, int b) {
    return (-1 * heap_pred_min(a, b));
}

/**
 * Allocate and return heap object of specified size.
 */
Heap* heap_alloc(int size, heap_pred predicate) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = size;
    h->keys = (long int*)malloc(size * sizeof(long int));
    memset(h->keys, 0, size * sizeof(long int));
    h->predicate = predicate;

    return h;
}

/**
 * Free the memory.
 */
void heap_free(Heap **h) {
    free((*h)->keys);
    free(*h);
    *h = NULL;
}

/**
 * Return heap size
 */
int heap_size(Heap *h) {
    return h->size;
}

/**
 * Maintain heap property.
 * Returns: -1 in case of error.
 */
void heapify(Heap *h, int index)
{
    int left = 2 * (index + 1) - 1;
    int right = 2 * (index + 1);
    int largest = index;

    if (left < h->size && h->predicate(h->keys[left], h->keys[index]) >= 0) {
        largest = left;
    }
    if (right < h->size && h->predicate(h->keys[right], h->keys[largest]) >= 0) {
        largest = right;
    }
    if (largest != index) {
        long int t = h->keys[index];
        h->keys[index] = h->keys[largest];
        h->keys[largest] = t;

        heapify(h, largest);
    }
}

/**
 * Build a heap from an array of integers.
 */
Heap* heap_build(long int *array, int size, heap_pred predicate) {
    Heap *h = heap_alloc(size, predicate);
    for (int ii = 0; ii < size; ii++) {
        h->keys[ii] = array[ii];
    }
    for (int ii = floor(h->size / 2) - 1; ii >= 0; ii--) {
        heapify(h, ii);
    }

    return h;
}

/**
 * Push an item into heap.
 * Returns: -1 if out of space.
 */
void heap_push(Heap *h, long int key)
{
    h->size += 1;
    h->keys = realloc(h->keys, h->size * sizeof(long int));
    h->keys[h->size - 1] = key;

    int current = h->size - 1;
    while (current > 0) {
        int parent = floor((current - 1) / 2);
        if (h->predicate(h->keys[current], h->keys[parent]) >= 0) {
            long int t = h->keys[current];
            h->keys[current] = h->keys[parent];
            h->keys[parent] = t;
            current = parent;
        } else {
            break;
        }
    }
}

/**
 * Pop an item from heap into value.
 * Returns: -1 if heap is empty.
 */
int heap_pop(Heap *h, long int *value)
{
    if (h->size == 0) {
        return -1;
    }

    *value = h->keys[0];

    h->keys[0] = h->keys[h->size - 1];
    h->size -= 1;
    h->keys = realloc(h->keys, h->size * sizeof(long int));

    heapify(h, 0);

    return 0;
}
