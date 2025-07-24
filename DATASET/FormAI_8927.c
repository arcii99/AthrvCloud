//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *count_words(void *arg);

int total_words = 0;

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(-1);
    }

    // Count the number of lines in the file
    int num_lines = 0;
    char line[512];
    while(fgets(line, sizeof(line), file) != NULL) {
        num_lines++;
    }

    // Start a thread for each line in the file
    pthread_t threads[num_lines];
    rewind(file);
    int i = 0;
    while(fgets(line, sizeof(line), file) != NULL) {
        char *str = strdup(line);
        pthread_create(&threads[i], NULL, count_words, str);
        i++;
    }

    // Wait for each thread to finish and add up the word count
    for (i = 0; i < num_lines; i++) {
        void *result;
        pthread_join(threads[i], &result);
        total_words += *((int *) result);
        free(result);
    }

    // Print the total word count
    printf("Total words: %d\n", total_words);

    // Close the file
    fclose(file);
    return 0;
}

void *count_words(void *arg) {
    char *line = (char *) arg;
    int num_words = 0;

    // Tokenize the line (delimiters: space and tab)
    char *token = strtok(line, " \t\n");
    while(token != NULL) {
        num_words++;
        token = strtok(NULL, " \t\n");
    }

    // Return the number of words in the line
    int *result = malloc(sizeof(int));
    *result = num_words;
    return result;
}