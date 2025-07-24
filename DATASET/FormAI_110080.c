//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// global variables
char** word_list;
int* word_count;
int num_words = 0;
pthread_mutex_t lock;

// worker function
void* count_words(void* arg) {
    int thread_id = *((int*) arg);
    int start = (num_words / MAX_THREADS) * thread_id;
    int end = thread_id == MAX_THREADS - 1 ? num_words : (num_words / MAX_THREADS) * (thread_id + 1);
    
    // count frequency of words in thread's designated range
    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&lock);
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(word_list[i], word_list[j]) == 0) {
                // word already in list, increase count
                word_count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            // add word to list
            word_list[num_words] = (char*) malloc(MAX_WORD_LENGTH);
            strcpy(word_list[num_words], word_list[i]);
            word_count[num_words] = 1;
            num_words++;
        }
        pthread_mutex_unlock(&lock);
    }
    
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./word_frequency <text_file>\n");
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }
    
    // initialize word list and count
    word_list = (char**) malloc(MAX_WORDS * sizeof(char*));
    word_count = (int*) calloc(MAX_WORDS, sizeof(int));
    
    // read file and tokenize into words
    char* token;
    char* delimiters = " .,:;!?()\n";
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, delimiters);
        while (token != NULL) {
            word_list[num_words] = (char*) malloc(MAX_WORD_LENGTH);
            strcpy(word_list[num_words], token);
            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded\n");
                return 1;
            }
            token = strtok(NULL, delimiters);
        }
    }
    fclose(file);
    
    // spawn threads to count frequencies
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, count_words, &thread_ids[i]) != 0) {
            printf("Error: Unable to create thread %d\n", i);
            return 1;
        }
    }
    
    // wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error: Unable to join thread %d\n", i);
            return 1;
        }
    }
    
    // print word frequencies in descending order
    for (int i = num_words - 1; i >= 0; i--) {
        printf("%s\t%d\n", word_list[i], word_count[i]);
    }
    
    // free memory
    for (int i = 0; i < num_words; i++) {
        free(word_list[i]);
    }
    free(word_list);
    free(word_count);
    
    return 0;
}