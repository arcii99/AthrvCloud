//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LEN 100
#define TABLE_SIZE 100000

// Simple hash table implementation
typedef struct {
    char **keys;
    int *values;
    int size;
} hash_table_t;

hash_table_t *table_create(int size) {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    table->keys = calloc(size, sizeof(char *));
    table->values = calloc(size, sizeof(int));
    table->size = size;
    return table;
}

int hash(char *s) {
    int hash = 0;
    while (*s != '\0') {
        hash = 31 * hash + *s;
        s++;
    }
    return hash;
}

void table_put(hash_table_t *table, char *key, int value) {
    int index = hash(key) % table->size;
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }
    if (table->keys[index] == NULL) {
        table->keys[index] = key;
    }
    table->values[index] += value;
}

int table_get(hash_table_t *table, char *key) {
    int index = hash(key) % table->size;
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }
    return table->values[index];
}

typedef struct {
    char *filename;
    hash_table_t *table;
} thread_arg_t;

// Thread function to count the frequency of words in a file.
void *count_words(void *arg) {
    thread_arg_t *args = (thread_arg_t *)arg;

    FILE *fp = fopen(args->filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", args->filename);
        return NULL;
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        table_put(args->table, word, 1);
    }

    fclose(fp);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int num_threads = 4;
    hash_table_t *table = table_create(TABLE_SIZE);

    pthread_t threads[num_threads];
    thread_arg_t args[num_threads];

    // Divide the file into equal chunks for each thread.
    int chunk_size = (int)((float)TABLE_SIZE / num_threads);

    for (int i = 0; i < num_threads; i++) {
        args[i].filename = argv[1];
        args[i].table = table_create(chunk_size);

        // Start the thread.
        pthread_create(&threads[i], NULL, count_words, &args[i]);
    }

    // Wait for all threads to finish.
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine the results from all threads.
    for (int i = 0; i < num_threads; i++) {
        for (int j = 0; j < args[i].table->size; j++) {
            if (args[i].table->keys[j] != NULL) {
                table_put(table, args[i].table->keys[j], args[i].table->values[j]);
            }
        }
    }

    // Print the results.
    for (int i = 0; i < table->size; i++) {
        if (table->keys[i] != NULL) {
            printf("%s: %d\n", table->keys[i], table->values[i]);
        }
    }

    return 0;
}