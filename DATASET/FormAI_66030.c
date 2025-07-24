//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000000
#define MAX_OUTPUT_LENGTH 1000

int num_threads;

typedef struct {
    char *input;
    char *output;
    int start_index;
    int end_index;
} Thread_Args;

void *summarize(void *args) {
    Thread_Args *thread_args = (Thread_Args *) args;
    char *input = thread_args->input;
    char *output = thread_args->output;
    int start_index = thread_args->start_index;
    int end_index = thread_args->end_index;

    // Initialize the summary output to empty string
    output[0] = '\0';

    // Process input and add important sentences to the output
    char *sentence_start = input;
    int sentence_length = 0;
    int num_sentences = 0;
    while (*input && input < input + end_index) {
        // Check if end of sentence
        if (*input == '.' || *input == '?' || *input == '!') {
            // Check if sentence has more than 10 words and contains a keyword
            if (sentence_length > 10 && strstr(sentence_start, "important") != NULL) {
                // Copy sentence to output
                strncat(output, sentence_start, sentence_length + 1);
                num_sentences++;
            }
            // Move sentence_start to next sentence
            sentence_start = input + 1;
            sentence_length = 0;
        } else {
            // Update length of current sentence
            sentence_length++;
        }
        // Move to next character
        input++;
    }

    // Print number of sentences found by this thread
    printf("Thread %ld found %d sentences\n", (long) pthread_self(), num_sentences);

    pthread_exit(NULL);
}

int main() {
    // Initialize input buffer
    char *input = (char *) calloc(MAX_INPUT_LENGTH, sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Error allocating memory for input buffer\n");
        exit(EXIT_FAILURE);
    }

    // Read input from file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }
    fread(input, sizeof(char), MAX_INPUT_LENGTH, fp);
    fclose(fp);

    // Initialize output buffer
    char *output = (char *) calloc(MAX_OUTPUT_LENGTH, sizeof(char));
    if (output == NULL) {
        fprintf(stderr, "Error allocating memory for output buffer\n");
        exit(EXIT_FAILURE);
    }

    // Get number of threads to use from user
    printf("Enter number of threads to use: ");
    scanf("%d", &num_threads);
    if (num_threads <= 0) {
        fprintf(stderr, "Number of threads must be greater than zero\n");
        exit(EXIT_FAILURE);
    }

    // Split input into chunks for each thread
    int chunk_size = MAX_INPUT_LENGTH / num_threads;
    Thread_Args *thread_args = (Thread_Args *) calloc(num_threads, sizeof(Thread_Args));
    if (thread_args == NULL) {
        fprintf(stderr, "Error allocating memory for thread arguments\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].input = input;
        thread_args[i].output = output;
        thread_args[i].start_index = i * chunk_size;
        thread_args[i].end_index = (i == num_threads - 1) ? MAX_INPUT_LENGTH : (i + 1) * chunk_size;
    }

    // Create threads and start summarization
    pthread_t *threads = (pthread_t *) calloc(num_threads, sizeof(pthread_t));
    if (threads == NULL) {
        fprintf(stderr, "Error allocating memory for threads\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_threads; i++) {
        int result = pthread_create(&threads[i], NULL, summarize, &thread_args[i]);
        if (result != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print final summary
    printf("\nFinal summary:\n%s\n", output);

    return 0;
}