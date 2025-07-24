//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10 // Size of the array to be sorted

int array[ARRAY_SIZE] = { 5, 2, 8, 10, 1, 4, 7, 9, 3, 6 }; // Array to be sorted

struct SortParams { 
    int start_index;
    int end_index;
}; // Struct to hold start and end index of each thread's section of the array

void *sort_section(void *parameters) {
    struct SortParams *params = (struct SortParams *)parameters;

    // Conduct bubble sort on section of the array
    for (int i = params->start_index; i <= params->end_index; i++) {
        for (int j = params->start_index; j <= params->end_index - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    pthread_exit(NULL); // Exit the thread once sorting is complete
}

int main() {
    pthread_t threads[2]; // Array to hold threads
    struct SortParams params[2]; // Array to hold parameters for each thread

    params[0].start_index = 0; // Set parameters for first thread
    params[0].end_index = ARRAY_SIZE / 2 - 1;
    pthread_create(&threads[0], NULL, sort_section, (void *)&params[0]);

    params[1].start_index = ARRAY_SIZE / 2; // Set parameters for second thread
    params[1].end_index = ARRAY_SIZE - 1;
    pthread_create(&threads[1], NULL, sort_section, (void *)&params[1]);

    // Wait for both threads to complete sorting
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}