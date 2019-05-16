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

int jarray_get_size(JArray *arrptr) {
    return arrptr->size;
}

int jarray_get_capacity(JArray *arrptr) {
    return arrptr->capacity;
}

bool jarray_is_empty(JArray *arrptr) {
    return arrptr->size <= 0;
}

int jarray_at(JArray *arrptr, int index) {
    if (index < 0 || index > arrptr->size -1) {
        exit(EXIT_FAILURE);
    }

    return *(arrptr->data + index);
}

int jarray_insert(JArray *arrptr, int value, int index) {
    if(index < 0 || index > arrptr->size-1) {
        exit(EXIT_FAILURE);
    }

    jarray_resize_for_size(arrptr, arrptr->size +1);

    int end_index = arrptr->size - 1;
    for (int i = end_index + 1; i > index; --i) {
        *(arrptr->data + i) = *(arrptr->data + i - 1);
    }

    *(arrptr->data + index) = value;
    arrptr->size += 1;
}

void jarray_prepend(JArray *arrptr, int item) {
    jarray_resize_for_size(arrptr, arrptr->size +1);
    int end_index = arrptr->size - 1;

    for (int i = end_index + 1; i > 0; --i) {
        *(arrptr->data + i) = *(arrptr->data + i -1);
    }

    *(arrptr->data) = item;
    arrptr->size += 1;
}

int jarray_pop(JArray *arrptr) {
    const int lastValue = *(arrptr->data + (arrptr->size - 1));
    jarray_resize_for_size(arrptr, arrptr->size - 1);
    arrptr->size -= 1;
    return lastValue;
}

void jarray_delete(JArray *arrptr, int index) {
    int end_index = arrptr->size - 1;
    if(index < 0 || index > end_index) {
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < end_index; ++i) {
        *(arrptr->data + i) = *(arrptr->data + i + 1);
    }

    jarray_resize_for_size(arrptr, arrptr->size - 1);
    arrptr->size -= 1;
}

void jarray_remove(JArray *arrptr, int value) {
    int end_index = arrptr->size - 1;

    for (int i = 0; i < end_index; i++) {
        if(value == *(arrptr->data + i)) {
            jarray_delete(arrptr, i);
        }
    }
}

int jarray_find(JArray *arrptr, int value) {
    int default_value = -1;
    for(int i = 0; i < arrptr->size; ++i) {
        if(*(arrptr->data + i ) == value ) {
            return i;
        }
    }

    return default_value;
}

// ========================

// TODO: Add tests
void run_all_tests() {}