#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <assert.h>
#include <stdbool.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

typedef struct JWImplementationArray {
    int size;
    int capacity;
    int *data;
} JArray;

// array functions

JArray *jarray_new(int capacity);
void jarray_push(JArray *arrptr, int value);
void jarray_resize_for_size(JArray *arrptr, int new_size);
int jarray_determine_capacity(int capacity);
void check_address(void *p);
void jarray_destroy(JArray *arrptr);
void jarray_print(JArray *arrptr);
int jarray_get_size(JArray *arrptr);
int jarray_get_capacity(JArray *arrptr);
bool jarray_is_empty(JArray *arrptr);
int jarray_at(JArray *arrptr, int index);
int jarray_insert(JArray *arrptr, int item, int index);
void jarray_prepend(JArray *arrptr, int item);
int jarray_pop(JArray *arrptr);
void jarray_delete(JArray *arrptr, int index);
void jarray_remove(JArray *arrptr, int value);
int jarray_find(JArray *arrptr, int value);

// tests
void run_all_tests();

#endif
