#include <stdio.h>
#include <stdlib.h>

#include "../src/heap.h"

int main(void) {
    Heap *high = heap_build(NULL, 0, heap_pred_min);
    Heap *low = heap_build(NULL, 0, heap_pred_max);

    long int mds = 0;
    long int n, t;
    while (scanf("%ld\n", &n) > 0) {
        if(low->size == 0) {
            heap_push(low, n);
        } else if(n < low->keys[0]) {
            heap_push(low, n);
        } else {
            heap_push(high, n);
        }

        if (abs(low->size - high->size) > 1) {
            if (low->size > high->size) {
                heap_pop(low, &t);
                heap_push(high, t);
            } else {
                heap_pop(high, &t);
                heap_push(low, t);
            }
        }

        if (low->size >= high->size) {
            mds += low->keys[0];
        } else {
            mds += high->keys[0];
        }
    }

    printf("%ld\n", mds);

    heap_free(&low);
    heap_free(&high);

    return 0;
}
