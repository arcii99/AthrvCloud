//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WORD_LEN 50  // Maximum length of a word in the input text
#define MAX_NUM_WORDS 5000 // Maximum number of unique words to store
#define MAX_LINE_LEN 1024 // Maximum length of a line in the input text
#define MAX_THREADS 50 // Maximum number of threads

typedef struct word_freq_t {
    char word[MAX_WORD_LEN]; // The word
    int frequency; // The frequency of the word
} word_freq_t;

word_freq_t word_freq_list[MAX_NUM_WORDS];  // The global word frequency list
int num_words; // The number of unique words in the input text
sem_t word_freq_list_semaphore;  // Semaphore to synchronize access to the global word frequency list
sem_t finished_semaphore; // Semaphore to indicate all threads are finished

void to_lowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_word(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

int compare_word_freq(const void* a, const void* b) {
    const word_freq_t *word_freq_a = (const word_freq_t*) a;
    const word_freq_t *word_freq_b = (const word_freq_t*) b;
    return word_freq_b->frequency - word_freq_a->frequency;
}

void print_word_freq_list() {
    qsort(word_freq_list, num_words, sizeof(word_freq_t), compare_word_freq); // Sort the word frequency list
    printf("WORD\tFREQUENCY\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_freq_list[i].word, word_freq_list[i].frequency);
    }
}

void* count_word_freq(void* arg) {
    int thread_num = *(int*) arg; // Get the thread number
    char buffer[MAX_LINE_LEN];
    char prev_char = ' ';
    char word[MAX_WORD_LEN];
    int word_len = 0;
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        printf("Thread %d: Error opening input file\n", thread_num);
        pthread_exit(NULL);
    }
    off_t offset = lseek(fd, thread_num * (lseek(fd, 0, SEEK_END) / MAX_THREADS), SEEK_SET); // Seek to the start position for this thread
    while (1) {
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            printf("Thread %d: Error reading from input file\n", thread_num);
            pthread_exit(NULL);
        }
        if (bytes_read == 0) { // End of file
            break;
        }
        for (int i = 0; i < bytes_read; i++) {
            if (isalpha(buffer[i])) { // Build the word
                word[word_len++] = tolower(buffer[i]);
                if (word_len == MAX_WORD_LEN) {
                    word_len--;
                }
            } else if (prev_char != ' ' && word_len > 0) { // End of word
                word[word_len] = '\0';
                if (is_valid_word(word)) {
                    sem_wait(&word_freq_list_semaphore); // Lock the word frequency list
                    int found = 0;
                    for (int j = 0; j < num_words; j++) {
                        if (strcmp(word, word_freq_list[j].word) == 0) {
                            found = 1;
                            word_freq_list[j].frequency++;
                            break;
                        }
                    }
                    if (!found && num_words < MAX_NUM_WORDS) {
                        strcpy(word_freq_list[num_words].word, word);
                        word_freq_list[num_words].frequency = 1;
                        num_words++;
                    }
                    sem_post(&word_freq_list_semaphore); // Unlock the word frequency list
                }
                word_len = 0;
            }
            prev_char = buffer[i];
        }
    }
    close(fd);
    sem_post(&finished_semaphore); // Signal that this thread is finished
    pthread_exit(NULL);
}

int main() {
    num_words = 0;
    sem_init(&word_freq_list_semaphore, 0, 1);
    sem_init(&finished_semaphore, 0, 0);
    pthread_t threads[MAX_THREADS];
    int thread_nums[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, count_word_freq, &thread_nums[i]);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        sem_wait(&finished_semaphore); // Wait for the thread to finish
    }
    sem_destroy(&word_freq_list_semaphore);
    sem_destroy(&finished_semaphore);
    print_word_freq_list();
    return 0;
}