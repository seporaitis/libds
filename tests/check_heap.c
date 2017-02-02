#include <stdlib.h>
#include <check.h>

#include "../src/heap.h"

START_TEST (test_heap_alloc)
{
    Heap *h = heap_alloc(10);
    ck_assert_ptr_ne(h, NULL);
}
END_TEST

START_TEST (test_heap_size)
{
    ck_assert_str_eq("AAA", "AAA");
}
END_TEST

START_TEST (test_heap_free)
{
    Heap *h = heap_alloc(10);
    heap_free(h);
    ck_assert_ptr_eq(h, NULL);
}
END_TEST


Suite *heap_suite(void)
{
    Suite *s;
    TCase *tc_heap;

    s = suite_create("heap");
    tc_heap = tcase_create("heap");

    tcase_add_test(tc_heap, test_heap_alloc);
    tcase_add_test(tc_heap, test_heap_size);
    tcase_add_test(tc_heap, test_heap_free);

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
