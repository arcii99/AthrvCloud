//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 50000

struct wordinfo {
    char word[MAX_WORD_LENGTH+1];
    int count;
};

int read_word(FILE *input_file, char *word_buffer, int max_word_length) {
    int word_length = 0;
    char ch;
    while ((ch = fgetc(input_file)) != EOF && !isalpha(ch));
    if (ch == EOF) {
        return 0;
    }
    word_buffer[word_length++] = ch;
    while (word_length < max_word_length && (ch = fgetc(input_file)) != EOF && isalpha(ch)) {
        word_buffer[word_length++] = ch;
    }
    word_buffer[word_length] = '\0';
    return word_length;
}

int compare_word_count(const void *a, const void *b) {
    const struct wordinfo *info_a = a;
    const struct wordinfo *info_b = b;
    return info_b->count - info_a->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        printf("Failed to open input file: %s\n", input_filename);
        return 1;
    }
    struct wordinfo words[MAX_NUM_WORDS];
    int num_words = 0;
    char word_buffer[MAX_WORD_LENGTH+1];
    while (read_word(input_file, word_buffer, MAX_WORD_LENGTH)) {
        if (num_words >= MAX_NUM_WORDS) {
            printf("Warning: Maximum number of words exceeded (limit=%d)\n", MAX_NUM_WORDS);
            break;
        }
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word_buffer) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[i].word, word_buffer);
            words[i].count = 1;
            num_words++;
        }
    }
    fclose(input_file);
    printf("%d unique words found\n", num_words);
    qsort(words, num_words, sizeof(struct wordinfo), compare_word_count);
    int i;
    printf("%-15s %s\n", "Word", "Count");
    for (i = 0; i < num_words; i++) {
        printf("%-15s %d\n", words[i].word, words[i].count);
    }
    return 0;
}