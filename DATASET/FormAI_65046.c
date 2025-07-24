//FormAI DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_THREADS 8
#define MAX_SPAM_WORDS 100
#define THRESHOLD 3

// function to check if a word is spam
bool is_spam(char* word, char** spam_words, int num_spam_words) {
    for (int i = 0; i < num_spam_words; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return true;
        }
    }
    return false;
}

// thread function to count the number of spam words in a given string
void* count_spam(void* args) {
    char* str = (char*) args;
    char* spam_words[MAX_SPAM_WORDS];
    int num_spam_words = 0;
    int spam_count = 0;

    // read the list of spam words from file
    FILE* fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        spam_words[num_spam_words++] = strdup(line);
    }
    fclose(fp);

    // tokenize the string
    char* token;
    char* rest = str;
    while ((token = strtok_r(rest, " \n\t", &rest))) {
        if (is_spam(token, spam_words, num_spam_words)) {
            spam_count++;
        }
    }

    // free memory
    for (int i = 0; i < num_spam_words; i++) {
        free(spam_words[i]);
    }

    return (void*) spam_count;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int spam_counts[MAX_THREADS];
    int num_threads = 0;

    // read input strings from file
    FILE* fp = fopen("input_strings.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        pthread_create(&threads[num_threads], NULL, count_spam, (void*) strdup(line));
        num_threads++;
        if (num_threads == MAX_THREADS) {
            break;
        }
    }
    fclose(fp);

    // wait for threads to finish and get results
    int total_spam_count = 0;
    for (int i = 0; i < num_threads; i++) {
        void* result;
        pthread_join(threads[i], &result);
        spam_counts[i] = (int) result;
        total_spam_count += spam_counts[i];
    }

    // determine if spam threshold is exceeded and print result
    if (total_spam_count > THRESHOLD) {
        printf("SPAM DETECTED\n");
    } else {
        printf("NOT SPAM\n");
    }
    
    return 0;
}