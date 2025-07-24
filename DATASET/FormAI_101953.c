//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_WORDS 1000

char* str_tolower(char* str) {
    char* ptr = str;
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
    return str;
}

int compare(const void* a, const void* b) {
    const char* a_str = *(const char**)a;
    const char* b_str = *(const char**)b;
    return strcmp(a_str, b_str);
}

int count_words(char* input, char* output) {
    int count = 0;
    char* words[MAX_WORDS];
    char* word_ptr;

    FILE* fp;
    fp = fopen(input, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token;
        char delimiters[] = " \n\t.,;()\"-";
        token = strtok(line, delimiters);
        while (token != NULL) {
            word_ptr = malloc(strlen(token) + 1);
            strcpy(word_ptr, token);
            str_tolower(word_ptr);
            words[count] = word_ptr;
            count++;
            token = strtok(NULL, delimiters);
        }
    }
    fclose(fp);

    qsort(words, count, sizeof(char*), compare);

    fp = fopen(output, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    int word_count = 1;
    for (int i = 1; i < count; i++) {
        if (strcmp(words[i], words[i-1]) != 0) {
            fprintf(fp, "%s: %d\n", words[i-1], word_count);
            word_count = 1;
        } else {
            word_count++;
        }
        free(words[i-1]);
    }
    fprintf(fp, "%s: %d\n", words[count-1], word_count);
    free(words[count-1]);
    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    return count_words(argv[1], argv[2]);
}