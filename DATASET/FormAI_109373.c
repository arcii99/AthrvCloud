//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 1000

int main() {
    char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    int frequencies[MAX_WORD_COUNT];
    int word_count = 0;
    char c;
    char current_word[MAX_WORD_LENGTH + 1];
    int length = 0;

    FILE *fp;
    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("File not found.");
        exit(0);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            current_word[length++] = tolower(c);
        } else if (length > 0) {
            current_word[length] = '\0';
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i], current_word) == 0) {
                    frequencies[i]++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(words[word_count], current_word);
                frequencies[word_count++] = 1;
            }

            length = 0;
        }
    }

    fclose(fp);

    printf("Word Frequency Counter\n\n");
    printf("%-20s%s\n", "Word", "Frequency");
    printf("--------------------  ----------\n");

    for (int i = 0; i < word_count; i++) {
        printf("%-20s%d\n", words[i], frequencies[i]);
    }

    return 0;
}