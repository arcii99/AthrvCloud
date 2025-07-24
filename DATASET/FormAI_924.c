//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5 // maximum number of threads
#define MAX_LOGS 1000 // maximum number of log entries
#define MAX_LOG_LENGTH 200 // maximum length of each log entry

char logs[MAX_LOGS][MAX_LOG_LENGTH]; // array to store log entries
int num_logs = 0; // variable to keep track of number of log entries

pthread_mutex_t lock; // mutex lock to synchronize access to logs array

void* read_logs(void* arg) {
    FILE* fp = fopen("logs.txt", "r"); // open logs file for reading
    if (fp == NULL) {
        printf("Error: Unable to open logs.txt\n");
        exit(1);
    }
    
    char temp[MAX_LOG_LENGTH];
    while (fgets(temp, MAX_LOG_LENGTH, fp) != NULL) { // read each line of logs file
        pthread_mutex_lock(&lock); // acquire lock before accessing logs array
        strcpy(logs[num_logs], temp); // copy log entry to logs array
        num_logs++; // increment number of log entries
        pthread_mutex_unlock(&lock); // release lock after accessing logs array
    }
    
    fclose(fp); // close logs file
    return NULL;
}

void* search_logs(void* arg) {
    int thread_id = *(int*)arg;
    
    char search_str[MAX_LOG_LENGTH];
    printf("Enter search string for thread %d: ", thread_id);
    fgets(search_str, MAX_LOG_LENGTH, stdin);
    search_str[strcspn(search_str, "\n")] = '\0'; // remove newline character from input
    
    int i;
    int num_matches = 0;
    for (i = 0; i < num_logs; i++) {
        if (strstr(logs[i], search_str) != NULL) { // search for search_str in log entry
            num_matches++;
            printf("[Thread %d]: Log %d contains \"%s\"\n", thread_id, i, search_str);
        }
    }
    
    printf("[Thread %d]: Found %d matches\n", thread_id, num_matches);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    
    pthread_mutex_init(&lock, NULL); // initialize mutex lock
    
    pthread_create(&threads[0], NULL, read_logs, NULL); // create read_logs thread
    pthread_join(threads[0], NULL); // wait for read_logs thread to complete
    
    int i;
    for (i = 1; i <= MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, search_logs, &i); // create search_logs thread with thread_id as argument
        pthread_join(threads[i], NULL); // wait for search_logs thread to complete
    }
    
    pthread_mutex_destroy(&lock); // destroy mutex lock
    
    return 0;
}