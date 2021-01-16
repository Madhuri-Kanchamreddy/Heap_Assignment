#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "appconst.h"
#include "heap.h"
#include "heap.c"

void test_heap_new(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    assert(heap->data[1] == 100);
    assert(heap_size(heap) == 10);
}

void test_heap_insert(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    heap = heap_insert(heap, 101);
    assert(heap->size == 11);
}

void test_get_max(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    int32_t max = heap_get_max(heap);
    assert(max == 100);
}

void test_max_heap(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    assert(heap_test(heap) == 1);
}

void test_extract_max(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    int32_t max = heap_extract_max(heap);
    assert(heap_test(heap));
}

void test_heap_sort(){
    int32_t input[] = {89, 99, 0, 2, 59, 10, 8, 40, 100, 36};
    Heap h;
    h = heap_new(input, 10);
    Heap *heap = &h;
    heap = heap_sort(heap);
    for(uint32_t i = 1; i <= heap->size; i++)
        printf("%d\t", heap->data[i]);
}

int main()
{
    test_heap_new();
    test_heap_insert();
    test_get_max();
    test_max_heap();
    test_extract_max();
    test_heap_sort();
    return 0;
}
