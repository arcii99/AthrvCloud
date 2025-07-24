//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

/* A struct to hold frequency count for a word */
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

/* A function to remove leading and trailing whitespace from a string */
void trim(char *str) {
    char *start = str;

    /* Remove leading whitespace */
    while (*start != '\0' && isspace(*start)) {
        start++;
    }

    /* Move remaining characters to beginning of string */
    memmove(str, start, strlen(start) + 1);

    /* Remove trailing whitespace */
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end+1) = '\0';
}

/* A function to find a word in an array of word counts */
WordCount *find_word(char *word, WordCount *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, word_counts[i].word) == 0) {
            return &word_counts[i];
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }

    int max_word_count = 1000;
    WordCount *word_counts = malloc(max_word_count * sizeof(WordCount));
    if (!word_counts) {
        fprintf(stderr, "Error: could not allocate memory for word counts.\n");
        fclose(file);
        return 1;
    }

    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, " \t\n");
        while (word) {
            trim(word);
            WordCount *word_count = find_word(word, word_counts, count);
            if (word_count) {
                word_count->count++;
            } else {
                if (count == max_word_count) {
                    max_word_count *= 2;
                    word_counts = realloc(word_counts, max_word_count * sizeof(WordCount));
                    if (!word_counts) {
                        fprintf(stderr, "Error: could not reallocate memory for word counts.\n");
                        fclose(file);
                        return 1;
                    }
                }
                strcpy(word_counts[count].word, word);
                word_counts[count].count = 1;
                count++;
            }
            word = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    printf("Word frequency:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}