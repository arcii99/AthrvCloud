//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>

struct search_data {
    int *array;
    int size;
    int target;
    int result;
    int done;
};

void* search_array_async(void* arg) {
    struct search_data* data = (struct search_data*) arg;
    int i;
    for (i = 0; i < data->size; i++) {
        if (data->array[i] == data->target) {
            data->result = i;
            break;
        }
    }
    data->done = 1;
    return NULL;
}

int main() {
    int array[] = {3, 5, 8, 4, 2, 9, 6};
    int size = sizeof(array)/sizeof(array[0]);
    int target = 4;

    struct search_data search;
    search.array = array;
    search.size = size;
    search.target = target;
    search.result = -1;
    search.done = 0;

    pthread_t thread;
    pthread_create(&thread, NULL, search_array_async, &search);

    // Do some other stuff while the search is running
    int i;
    for (i = 0; i < 100000000; i++) {
        // Do some arbitrary calculation to simulate other work
        int j = i * 2;
        j /= 3;
    }

    // Check if the search is done
    while (!search.done) {
        // Wait for the search to complete
    }

    // Print the result
    if (search.result >= 0) {
        printf("Target found at index %d\n", search.result);
    } else {
        printf("Target not found\n");
    }

    return 0;
}