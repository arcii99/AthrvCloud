//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_PARANOIA_LEVEL 3

char* read_file(char* filename);
int count_words(char* text, char* word);
void remove_punctuation(char* s);
char* to_lower_case(char* s);
void display_results(int* counts, int n, char* word);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a filename as an argument.\n");
        exit(1);
    }
    char* text = read_file(argv[1]);

    // remove punctuation and convert to lowercase
    remove_punctuation(text);
    char* lowercase_text = to_lower_case(text);

    int word_count = 0;
    char* words[MAX_WORD_LEN];
    char* token = strtok(lowercase_text, " \n\t");
    while (token != NULL) {
        // add word to array if not already present
        int i, found = 0;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            words[word_count] = malloc(strlen(token) + 1);
            strcpy(words[word_count], token);
            word_count++;
        }

        token = strtok(NULL, " \n\t");
    }

    int* counts = malloc(sizeof(int) * word_count);
    int i;
    for (i = 0; i < word_count; i++) {
        counts[i] = count_words(lowercase_text, words[i]);
    }

    // display paranoia levels
    printf("Paranoia level 1:\n");
    for (i = 0; i < word_count; i++) {
        display_results(counts, word_count, words[i]);
    }

    printf("\nParanoia level 2:\n");
    for (i = 0; i < word_count; i++) {
        if (counts[i] >= 5) {
            display_results(counts, word_count, words[i]);
        }
    }

    printf("\nParanoia level 3:\n");
    for (i = 0; i < word_count; i++) {
        if (counts[i] >= 10) {
            display_results(counts, word_count, words[i]);
        }
    }

    return 0;
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, fp);
    fclose(fp);

    buffer[size] = '\0';
    return buffer;
}

int count_words(char* text, char* word) {
    char* token = strtok(text, " \n\t");
    int count = 0;
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " \n\t");
    }
    return count;
}

void remove_punctuation(char* s) {
    char* p = s;
    while (*p != '\0') {
        if (!isalpha(*p)) {
            *p = ' ';
        }
        p++;
    }
}

char* to_lower_case(char* s) {
    char* p = s;
    while (*p != '\0') {
        *p = tolower(*p);
        p++;
    }
    return s;
}

void display_results(int* counts, int n, char* word) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(word, word[i]) == 0) {
            printf("%s: %d\n", word, counts[i]);
            break;
        }
    }
}