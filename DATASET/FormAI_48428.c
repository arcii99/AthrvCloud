//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <time.h>

/* Array size */
#define ARRAY_SIZE 1000000

/* Function to generate random numbers */
int get_random_number() {
    return rand() % 10000;
}

/* Function to initialize array */
void initialize_array(int *array) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = get_random_number(); 
    }
}

/* Function to print array */
void print_array(int *array) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Function to bubble sort array */
void bubble_sort(int *array) {
    int i, j;
    for (i = 0; i < ARRAY_SIZE-1; i++)
        for (j = 0; j < ARRAY_SIZE-i-1; j++)
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}

/* Function to swap two numbers */
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to copy array */
void copy_array(int *src, int *dest) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];
    clock_t t1, t2;
    double time_taken;
    
    /* Initialize array1 */
    initialize_array(array1);
    
    /* Copy array1 to array2 */
    copy_array(array1, array2);
    
    /* Sort array1 using bubble sort */
    t1 = clock();
    bubble_sort(array1);
    t2 = clock();
    time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to execute.\n", time_taken);
    
    /* Print sorted array1 */
    printf("Sorted Array:\n");
    print_array(array1);
    
    return 0;
}