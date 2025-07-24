//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

/* Function prototypes */
void count_words(FILE* fp, int* total_words, int* unique_words);
int is_separator(char c);

int main(int argc, char *argv[]) {
    FILE* fp;
    int total_words = 0;
    int unique_words = 0;
    
    if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    count_words(fp, &total_words, &unique_words);

    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", unique_words);

    fclose(fp);

    return 0;
}

/* Count total number of words and unique words in the given file */
void count_words(FILE* fp, int* total_words, int* unique_words) {
    char word[MAX_WORD_LENGTH + 1];
    int word_count[MAX_WORD_LENGTH + 1] = {0};
    int word_index = 0;
    int i;

    while(1) {
        char c = fgetc(fp);
        if(c == EOF) {
            break;
        }

        if(is_separator(c)) {
            if(word_index > 0) {
                word[word_index] = '\0';
                (*total_words)++;
                word_count[word_index]++;
                word_index = 0;
            }
        } else {
            if(word_index < MAX_WORD_LENGTH) {
                word[word_index++] = tolower(c);
            }
        }
    }

    for(i = 1; i < MAX_WORD_LENGTH; i++) {
        if(word_count[i] > 0) {
            (*unique_words)++;
        }
    }
}

/* Check if the given character is a separator */
int is_separator(char c) {
    if(c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == ',' || c == '.' || c == ';' || c == ':' || c == '\'' || c == '\"') {
        return 1;
    }

    return 0;
}