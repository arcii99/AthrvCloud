//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LENGTH 1024

struct thread_args {
    char* str;
    int* count;
};

void* count_chars(void* arg) {
    struct thread_args* args = (struct thread_args*) arg;
    int count = 0;
    for (int i = 0; i < strlen(args->str); i++) {
        if (isalpha(args->str[i])) count++;
    }
    *(args->count) = count;
    return NULL;
}

int main() {
    char input[MAX_LENGTH];
    int char_count = 0;

    printf("Welcome to the Typing Speed Test.\n");
    printf("Please type the following sentence:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    pthread_t count_thread;
    struct thread_args args;
    args.str = input;
    args.count = &char_count;

    printf("Calculating...\n");

    if (pthread_create(&count_thread, NULL, count_chars, &args)) {
        fprintf(stderr, "Error creating thread.\n");
        return 1;
    }

    if (pthread_join(count_thread, NULL)) {
        fprintf(stderr, "Error joining thread.\n");
        return 1;
    }

    float wpm = (float) char_count / 5 / 0.5;
    printf("You typed %d characters in 0.5 seconds.\n", char_count);
    printf("Your typing speed is approximately %.2f words per minute.\n", wpm);

    return 0;
}