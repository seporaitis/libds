TESTS = check_heap

check_PROGRAMS = check_heap
check_heap_SOURCES = check_heap.c $(top_builddir)/src/heap.h
check_heap_CFLAGS = @CHECK_CFLAGS@
check_heap_LDADD = $(top_builddir)/src/libds.la @CHECK_LIBS@ -lsubunit -lrt -lpthread -lm
