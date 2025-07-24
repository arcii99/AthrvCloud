//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Limit for the maximum word length

int main() {
    char word[MAX_WORD_LENGTH + 1];
    int count = 0;

    FILE *fp = fopen("sample_text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) == 1) {
        if (tolower(word[0]) == 'c') {
            count++;
        }
    }

    printf("Number of words starting with 'C': %d\n", count);

    fclose(fp);
    return 0;
}