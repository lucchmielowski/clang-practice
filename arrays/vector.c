// Vector implementation
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

/* Calculate capacity using growthFactor */
int jarray_determine_capacity(int capacity) {
    const int kMinInitialCapacity = 1;
    int true_capacity = kMinCapacity;

    if(capacity < kMinInitialCapacity) {
        exit(EXIT_FAILURE);
    }

    while(capacity > true_capacity / kGrowthFactor) {
        true_capacity *= kGrowthFactor;
    }

    return true_capacity;
}

JArray *jarray_new(int capacity) {
    int true_capacity = jarray_determine_capacity(capacity);
    JArray *arrptr = malloc(sizeof(JArray));
    check_address(arrptr);

    arrptr->size = 0;
    arrptr->capacity = true_capacity;
    // Allocate int_size * number of elements in array
    arrptr->data = (int *)(malloc(sizeof(int) * true_capacity));
    check_address(arrptr->data);

    return arrptr;
}

void jarray_upsize(JArray *arrptr) {
    int old_capacity = arrptr->capacity;
    int new_capacity = jarray_determine_capacity(old_capacity);

    int *new_data = (int *)(malloc(sizeof(int) * new_capacity));
    check_address(new_data);

    // Free memory before assigning new values
    free(arrptr->data);

    arrptr->capacity = new_capacity;
    arrptr->data = new_data;
}

void jarray_downsize(JArray *arrptr) {
    int old_capacity = arrptr->capacity;
    int new_capacity = arrptr->capacity / kGrowthFactor;

    if(new_capacity < kMinCapacity) {
        new_capacity = kMinCapacity;
    }

    if (new_capacity != old_capacity) {
        int *new_data =(int *)(malloc(sizeof(int) * new_capacity));
        check_address(new_data);

        for(int i = 0; i < new_capacity; ++i) {
            *(new_data + i) = *(arrptr->data + i);
        }

        free(arrptr->data);
        arrptr->data = new_data;
        arrptr->capacity = new_capacity;
    }
}

void jarray_resize_for_size(JArray *arrptr, int new_size) {
    if(arrptr->size < new_size) { // grow
        if(arrptr->size == arrptr->capacity) {
            jarray_upsize(arrptr);
        }
    } else if (arrptr->size > new_size) { // shrink
        if(arrptr->size < arrptr->capacity / kShrinkFactor) {
            jarray_downsize(arrptr);
        }
    }
}

// Push a value into the array
void jarray_push(JArray *arrptr, int value) {
    jarray_resize_for_size(arrptr, arrptr->size + 1);

    *(arrptr->data + arrptr->size) = value;
    ++(arrptr->size);
}

void check_address(void *p) {
    if (p == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

void jarray_destroy(JArray *p) {
    free(p->data);
    free(p);
}

void jarray_print(JArray *arrptr) {
    printf("Size: %d\n", arrptr->size);
    printf("Capacity: %d\n", arrptr->capacity);

    printf("Items:\n");
    for (int i = 0; i < arrptr->size; ++i) {
        printf("%d : %d \n", i, *(arrptr->data + i));
    }

    printf("------------------------\n");
}

// ========================

// TODO: Add tests
void run_all_tests() {}