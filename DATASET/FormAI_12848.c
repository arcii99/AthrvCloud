//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
// A unique threading library implementation example program
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define a structure for our custom thread info
typedef struct {
    pthread_t thread_id;         // ID of the thread
    int thread_num;              // Unique numeric ID for the thread
    char* message;              // The message each thread should print
} thread_info;

// Define the thread function
void *thread_func(void *arg) {
    thread_info *tinfo = (thread_info *) arg;
    printf("Thread #%d says: %s", tinfo->thread_num, tinfo->message);
    pthread_exit(NULL);
}

// Define the main function
int main() {
    int num_threads = 5;
    thread_info *tinfo_arr = malloc(sizeof(thread_info) * num_threads);
    if (tinfo_arr == NULL) {
        printf("Error: memory allocation failure\n");
        return 1;
    }

    // Create the threads and set their info
    for (int i = 0; i < num_threads; i++) {
        tinfo_arr[i].thread_num = i;
        tinfo_arr[i].message = "Hello from thread!\n";
        if (pthread_create(&tinfo_arr[i].thread_id, NULL, thread_func, &tinfo_arr[i])) {
            printf("Error: failed to create thread\n");
            return 1;
        }
    }

    // Wait for all threads to finish and clean up
    for (int i = 0; i < num_threads; i++) {
        pthread_join(tinfo_arr[i].thread_id, NULL);
    }
    free(tinfo_arr);

    return 0;
}