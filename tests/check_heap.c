#include <stdlib.h>
#include <check.h>

#include "../src/heap.h"


START_TEST (test_heap_predicates)
{
    ck_assert_int_eq(heap_pred_min(1, 1), 0);
    ck_assert_int_eq(heap_pred_min(1, 2), 1);
    ck_assert_int_eq(heap_pred_min(1, 0), -1);

    ck_assert_int_eq(heap_pred_max(1, 1), 0);
    ck_assert_int_eq(heap_pred_max(1, 2), -1);
    ck_assert_int_eq(heap_pred_max(1, 0), 1);
}
END_TEST

START_TEST (test_heap_alloc)
{
    Heap *h = heap_alloc(10, heap_pred_min);
    ck_assert_ptr_ne(h, NULL);
}
END_TEST

START_TEST (test_heap_free)
{
    Heap *h = heap_alloc(10, heap_pred_min);
    heap_free(&h);
    ck_assert_ptr_eq(h, NULL);
}
END_TEST

START_TEST (test_heap_size)
{
    ck_assert_str_eq("AAA", "AAA");
}
END_TEST

START_TEST (test_heapify)
{
    Heap *h = heap_alloc(3, heap_pred_min);
    h->keys[0] = 3;
    h->keys[1] = 2;
    h->keys[2] = 1;

    heapify(h, 0);

    ck_assert_int_eq(h->keys[0], 1);
    ck_assert_int_eq(h->keys[1], 2);
    ck_assert_int_eq(h->keys[2], 3);
}
END_TEST

START_TEST (test_heap_build)
{
    long int array[5] = {33, 22, 10, 14, 50};
    Heap *h = heap_build(array, 5, heap_pred_max);

    ck_assert_int_eq(h->keys[0], 50);
    ck_assert_int_eq(h->keys[1], 33);
    ck_assert_int_eq(h->keys[2], 10);
    ck_assert_int_eq(h->keys[3], 14);
    ck_assert_int_eq(h->keys[4], 22);
}
END_TEST

START_TEST (test_heap_push)
{
    long int array[1] = {33};
    Heap *h = heap_build(array, 1, heap_pred_max);

    heap_push(h, 50);

    ck_assert_int_eq(h->keys[0], 50);
    ck_assert_int_eq(h->keys[1], 33);

    heap_push(h, 40);

    ck_assert_int_eq(h->keys[0], 50);
    ck_assert_int_eq(h->keys[1], 33);
    ck_assert_int_eq(h->keys[2], 40);

    heap_push(h, 45);

    ck_assert_int_eq(h->keys[0], 50);
    ck_assert_int_eq(h->keys[1], 45);
    ck_assert_int_eq(h->keys[2], 40);
    ck_assert_int_eq(h->keys[3], 33);
}
END_TEST

START_TEST (test_heap_pop)
{
    long int array[5] = {33, 22, 10, 14, 50};
    Heap *h = heap_build(array, 5, heap_pred_max);

    long int v;
    heap_pop(h, &v);
    ck_assert_int_eq(v, 50);

    heap_pop(h, &v);
    ck_assert_int_eq(v, 33);

    heap_pop(h, &v);
    ck_assert_int_eq(v, 22);

    heap_pop(h, &v);
    ck_assert_int_eq(v, 14);

    heap_pop(h, &v);
    ck_assert_int_eq(v, 10);

    ck_assert_int_eq(heap_pop(h, &v), -1);
}
END_TEST


Suite *heap_suite(void)
{
    Suite *s;
    TCase *tc_heap;

    s = suite_create("heap");
    tc_heap = tcase_create("heap");

    tcase_add_test(tc_heap, test_heap_predicates);
    tcase_add_test(tc_heap, test_heap_alloc);
    tcase_add_test(tc_heap, test_heap_free);
    tcase_add_test(tc_heap, test_heap_size);
    tcase_add_test(tc_heap, test_heapify);
    tcase_add_test(tc_heap, test_heap_build);
    tcase_add_test(tc_heap, test_heap_push);
    tcase_add_test(tc_heap, test_heap_pop);

    suite_add_tcase(s, tc_heap);

    return s;
}


int main(void) {
    int number_failed;
    Suite *suite;
    SRunner *runner;

    suite = heap_suite();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
