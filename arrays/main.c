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
    printf("Enter how many numbers would you like to store : \n");
    scanf("%d", &capacity);

    printf("You'll be storing %d elements\n", capacity);
    JArray* arrptr = jarray_new(capacity);

   for (int d = 1; d <= capacity; d++) {
        jarray_push(arrptr, d);
    }
    printf("Inserting value :\n");
    jarray_insert(arrptr, 12, 3);

    printf("Prepend value\n");
    jarray_prepend(arrptr, 444);

    int popped = jarray_pop(arrptr);
    printf("Popped value : %d\n", popped);

    jarray_delete(arrptr, 2);
    jarray_remove(arrptr, 12);
    printf("jarray_find(5) Result : %d\n", jarray_find(arrptr, 5));


    jarray_print(arrptr);
    jarray_destroy(arrptr);
}