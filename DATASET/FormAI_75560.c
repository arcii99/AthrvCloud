//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORD_LEN 100

typedef struct {
    char** words;
    int* freqs;
    int total_words;
} WordList;

/* Function to count the frequency of word in a given string */
void count_words(char* string, WordList* word_list) {
    char delimiters[] = " \t\n,.!?\";:-+()*&^%$#@~`";
    char* word = strtok(string, delimiters);
    
    while (word != NULL) {
        int index = -1;
        for (int i = 0; i < word_list->total_words; i++) {
            if (strcmp(word, word_list->words[i]) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            int word_index = word_list->total_words;
            word_list->words[word_index] = word;
            word_list->freqs[word_index] = 1;
            word_list->total_words++;
        }
        else {
            word_list->freqs[index]++;
        }
        
        word = strtok(NULL, delimiters);
    }
}

/* Worker function for each thread */
void* word_count_thread(void* thread_arg) {
    WordList* word_list = (WordList*) thread_arg;
    int num_words = word_list->total_words;
    
    for (int i = 0; i < num_words; i++) {
        char* word = word_list->words[i];
        int freq = word_list->freqs[i];
        
        printf("%s: %d\n", word, freq);
    }
    
    return NULL;
}

/* Main function */
int main(int argc, char* argv[]) {
    char* input_file = argv[1];
    FILE* file = fopen(input_file, "r");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", input_file);
        return 1;
    }
    
    pthread_t threads[MAX_THREADS];
    WordList word_lists[MAX_THREADS];
    int num_threads = 0;
    
    while (!feof(file)) {
        char line[MAX_WORD_LEN];
        if (fgets(line, MAX_WORD_LEN, file) != NULL) {
            int i = num_threads % MAX_THREADS;
            WordList* current_word_list = &word_lists[i];
            current_word_list->words = malloc(sizeof(char*) * MAX_WORD_LEN);
            current_word_list->freqs = malloc(sizeof(int) * MAX_WORD_LEN);
            current_word_list->total_words = 0;
            count_words(line, current_word_list);
            
            if (num_threads >= MAX_THREADS) {
                /* Wait for previous batch of threads to finish before starting new batch */
                for (int j = 0; j < MAX_THREADS; j++) {
                    pthread_join(threads[j], NULL);
                }
            }
            
            pthread_create(&threads[i], NULL, word_count_thread, current_word_list);
            num_threads++;
        }
    }
    
    /* Wait for all threads to finish */
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        free(word_lists[i].words);
        free(word_lists[i].freqs);
    }
    
    fclose(file);
    return 0;
}