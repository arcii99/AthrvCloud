//FormAI DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main(int argc, char *argv[]) {
    FILE *fp;
    int count = 0;
    char word[MAX_WORD_LENGTH];

    if (argc != 2) {
        printf("Please enter only one file name as argument.\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    while (fscanf(fp, "%s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if word starts with 'c'
        if (word[0] == 'c') {
            count++;
        }
    }

    printf("Number of words starting with 'c' in file %s: %d\n", argv[1], count);

    fclose(fp);
    return 0;
}