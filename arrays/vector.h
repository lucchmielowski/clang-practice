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

// tests
void run_all_tests();

#endif
