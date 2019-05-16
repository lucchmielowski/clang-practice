#include<stdio.h>
#include<stdlib.h>
#include "vector.c"

void run_example();

int main() {
    //run_all_tests();
    run_example();
    return EXIT_SUCCESS;
}

void run_example() {
    int capacity = 0;
    printf("Enter how many numbers would you like to store : ");
    scanf("%d", &capacity);

    printf("You'll be storing %d elements", capacity);
    JArray* arrptr = jarray_new(capacity);

    for (int d = 1; d <= capacity; d++) {
        jarray_push(arrptr, d);
    }

    jarray_print(arrptr);
    jarray_destroy(arrptr);
}