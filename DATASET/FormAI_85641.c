//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

// Define the maximum length of a message and the maximum number of threads
#define MAX_MSG_LENGTH 100
#define MAX_THREADS 5

// Define a struct to hold thread information
typedef struct {
    int id;
    char message[MAX_MSG_LENGTH];
    bool is_spam;
} thread_data;

// Define the words that we consider to be spam
const char *SPAM_WORDS[] = {"buy", "click", "subscribe", "win", "limited time offer", "free"};

// Define the function that the threads will run
void *check_spam(void *arg) {
    thread_data *data = (thread_data *)arg;
    data->is_spam = false;
    for (int i=0; i < sizeof(SPAM_WORDS) / sizeof(char *); i++) {
        if (strstr(data->message, SPAM_WORDS[i]) != NULL) {
            data->is_spam = true;
            break;
        }
    }
    printf("Thread %d: message '%s' is %s\n", data->id, data->message, data->is_spam ? "spam" : "not spam");
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[MAX_THREADS];
    thread_data thread_data_array[MAX_THREADS];
    char input[MAX_MSG_LENGTH];

    // Get user input
    printf("Please enter a message to check for spam:\n");
    fgets(input, MAX_MSG_LENGTH, stdin);

    // Split the input into parts and create threads to check for spam
    char *token = strtok(input, " \n");
    int num_threads = 0;
    while (token != NULL && num_threads < MAX_THREADS) {
        thread_data_array[num_threads].id = num_threads;
        strncpy(thread_data_array[num_threads].message, token, MAX_MSG_LENGTH);
        pthread_create(&threads[num_threads], NULL, check_spam, (void *)&thread_data_array[num_threads]);
        token = strtok(NULL, " \n");
        num_threads++;
    }

    // Wait for the threads to complete and print a report
    bool all_not_spam = true;
    for (int i=0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        all_not_spam &= !thread_data_array[i].is_spam;
    }
    printf("Overall classification: %s\n", all_not_spam ? "not spam" : "spam");

    return 0;
}