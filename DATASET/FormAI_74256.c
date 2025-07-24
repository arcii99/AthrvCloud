//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_CHARS 100

char text[MAX_LINES][MAX_CHARS]; // 2D array to store the input text
int countVowels[MAX_LINES] = {0}; // array to store the count of vowels in each line
pthread_mutex_t lock; // mutex lock to prevent race condition

// function to count the number of vowels in a given string
int count_vowels(char *str) {
    int vowels = 0;
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        switch(tolower(str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
        }
    }
    return vowels;
}

// function to process a line of text
void process_text(int line_no) {
    // acquire lock to prevent race condition
    pthread_mutex_lock(&lock);

    printf("Processing line %d...\n", line_no);
    countVowels[line_no] = count_vowels(text[line_no]);

    // release lock
    pthread_mutex_unlock(&lock);
}

// thread function to process multiple lines of text
void* process_multiple_lines(void* arg) {
    int* line_no = (int*) arg;

    // process line
    process_text(*line_no);

    pthread_exit(NULL);
}

int main() {
    // read input text from user
    printf("Enter %d lines of text:\n", MAX_LINES);
    for(int i=0; i<MAX_LINES; i++) {
        fgets(text[i], MAX_CHARS, stdin);
    }

    // create threads to process each line of text
    pthread_t thread_ids[MAX_LINES];
    int line_no[MAX_LINES];
    for(int i=0; i<MAX_LINES; i++) {
        line_no[i] = i;
        pthread_create(&thread_ids[i], NULL, process_multiple_lines, &line_no[i]);
    }

    // wait for all threads to complete
    for(int i=0; i<MAX_LINES; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // print the count of vowels in each line
    printf("Count of vowels in each line:\n");
    for(int i=0; i<MAX_LINES; i++) {
        printf("Line %d: %d\n", i+1, countVowels[i]);
    }

    return 0;
}