//FormAI DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

// Function prototypes
bool is_valid_word(char *word);
void *spell_check_words(void *args);
void print_misspelled_words();
void cleanup();

// Struct to hold thread arguments
struct thread_args {
    char **words;
    int num_words;
    int *misspelled_word_count;
};

// Global variables
char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int num_dictionary_words = 0;
char input_text[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int num_input_words = 0;
char misspelled_words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int num_misspelled_words = 0;
pthread_mutex_t lock;
pthread_t threads[4];
int thread_args_index = 0;
struct thread_args thread_args_array[4];

int main() {
    // Open dictionary file
    FILE *dictionary_file = fopen("words.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error opening dictionary file");
        exit(1);
    }
    
    // Load dictionary words into memory
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, dictionary_file) != NULL) {
        word[strcspn(word, "\r\n")] = '\0'; // remove newline characters
        strcpy(dictionary[num_dictionary_words], word);
        num_dictionary_words++;
    }
    fclose(dictionary_file);
    
    // Open input text file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file");
        exit(1);
    }
    
    // Load input words into memory
    while (fscanf(input_file, "%s", word) != EOF) {
        if (strlen(word) < MAX_WORD_LENGTH && is_valid_word(word)) {
            strcpy(input_text[num_input_words], word);
            num_input_words++;
        }
    }
    fclose(input_file);
    
    // Initialize mutex lock for multithreading
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Error initalizing mutex lock");
        exit(1);
    }
    
    // Create threads to spell check input words
    int i;
    for (i = 0; i < 4; i++) {
        thread_args_array[i].words = input_text + (i * num_input_words / 4);
        thread_args_array[i].num_words = num_input_words / 4;
        thread_args_array[i].misspelled_word_count = malloc(sizeof(int));
        *(thread_args_array[i].misspelled_word_count) = 0;
        pthread_create(&threads[i], NULL, spell_check_words, (void *)&thread_args_array[i]);
    }
    
    // Wait for threads to finish
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print misspelled words
    print_misspelled_words();
    
    // Cleanup
    cleanup();
    
    return 0;
}

bool is_valid_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

void *spell_check_words(void *args) {
    struct thread_args *thread_args = (struct thread_args *)args;
    int i, j;
    for (i = 0; i < thread_args->num_words; i++) {
        bool found_in_dictionary = false;
        for (j = 0; j < num_dictionary_words; j++) {
            if (strcmp(thread_args->words[i], dictionary[j]) == 0) {
                found_in_dictionary = true;
                break;
            }
        }
        if (!found_in_dictionary) {
            pthread_mutex_lock(&lock);
            strcpy(misspelled_words[num_misspelled_words], thread_args->words[i]);
            num_misspelled_words++;
            *(thread_args->misspelled_word_count) += 1;
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_exit(NULL);
}

void print_misspelled_words() {
    int i;
    printf("Misspelled words:\n");
    for (i = 0; i < num_misspelled_words; i++) {
        printf("%s\n", misspelled_words[i]);
    }
}

void cleanup() {
    int i;
    for (i = 0; i < 4; i++) {
        free(thread_args_array[i].misspelled_word_count);
    }
    pthread_mutex_destroy(&lock);
}