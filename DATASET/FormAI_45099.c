//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ELEMENTS 1000

int data[MAX_ELEMENTS];
int num_elements = 0;
pthread_mutex_t mutex;

// Function to generate random data
void generate_data() {
    for (int i=0; i<MAX_ELEMENTS; i++) {
        data[i] = rand() % 1000;
        num_elements++;
    }
}

// Function to print data array
void print_data() {
    for (int i=0; i<num_elements; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// Function to binary search for a key in the data array
int binary_search(int key) {
    int low = 0, high = num_elements - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] == key) {
            return mid;
        }
        else if (key < data[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

// Thread function to search for a key in the data array
void *search(void *arg) {
    int key = *((int *) arg);
    pthread_mutex_lock(&mutex);
    int index = binary_search(key);
    if (index != -1) {
        printf("%d found at index %d\n", key, index);
    } else {
        printf("%d not found\n", key);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    generate_data();
    print_data();

    int num_threads;
    printf("Enter number of threads (1 - %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    pthread_t thread[num_threads];
    int keys[num_threads];

    for (int i=0; i<num_threads; i++) {
        printf("Enter key to search: ");
        scanf("%d", &keys[i]);
        pthread_create(&thread[i], NULL, search, &keys[i]);
    }

    for (int i=0; i<num_threads; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}