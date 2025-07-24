//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50  // Maximum length of a word.
#define MAX_FILE_SIZE 1000   // Maximum size of the input text file.

struct word_counter {
    char word[MAX_WORD_LENGTH];
    int count;
};

int read_file(char *filename, char *text);
void clean_text(char *text);
int count_words(char *text, struct word_counter *counters);
void sort_counters(struct word_counter *counters, int num_counters);
void print_counters(struct word_counter *counters, int num_counters);

int main(int argc, char *argv[]) {
    char text[MAX_FILE_SIZE];
    struct word_counter counters[MAX_FILE_SIZE];
    int num_counters;

    if (argc != 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        exit(1);
    }

    int num_chars = read_file(argv[1], text);
    if (num_chars == -1) {
        printf("Error reading file '%s'\n", argv[1]);
        exit(1);
    }

    clean_text(text);

    num_counters = count_words(text, counters);
    if (num_counters == 0) {
        printf("No words found in file '%s'\n", argv[1]);
        exit(1);
    }

    sort_counters(counters, num_counters);
    print_counters(counters, num_counters);

    return 0;
}

int read_file(char *filename, char *text) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    int num_chars = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        text[num_chars++] = c;
        if (num_chars >= MAX_FILE_SIZE) {
            break;
        }
    }

    fclose(file);
    return num_chars;
}

void clean_text(char *text) {
    int i, j = 0;
    int len_text = strlen(text);

    for (i = 0; i < len_text; i++) {
        // Replace non-word characters with spaces.
        if (!isalpha(text[i])) {
            text[i] = ' ';
        }

        // Reduce multiple spaces to a single space.
        if (text[i] == ' ' && (i == 0 || text[i-1] == ' ')) {
            continue;
        }

        // Convert to lowercase.
        text[j++] = tolower(text[i]);
    }

    if (j > 0 && text[j-1] == ' ') {
        j--;
    }

    text[j] = '\0';
}

int count_words(char *text, struct word_counter *counters) {
    char *saveptr;
    char *word = strtok_r(text, " ", &saveptr);
    int num_counters = 0;

    while (word != NULL) {
        int i;
        for (i = 0; i < num_counters; i++) {
            if (strcmp(counters[i].word, word) == 0) {
                counters[i].count++;
                break;
            }
        }

        if (i == num_counters) {
            strncpy(counters[i].word, word, MAX_WORD_LENGTH);
            counters[i].count = 1;
            num_counters++;
        }

        word = strtok_r(NULL, " ", &saveptr);
    }

    return num_counters;
}

void sort_counters(struct word_counter *counters, int num_counters) {
    int i, j;

    for (i = 0; i < num_counters-1; i++) {
        for (j = i+1; j < num_counters; j++) {
            if (counters[i].count < counters[j].count) {
                struct word_counter temp = counters[i];
                counters[i] = counters[j];
                counters[j] = temp;
            }
        }
    }
}

void print_counters(struct word_counter *counters, int num_counters) {
    int i;
    for (i = 0; i < num_counters; i++) {
        printf("%s: %d\n", counters[i].word, counters[i].count);
    }
}