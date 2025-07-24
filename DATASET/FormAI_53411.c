//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define WORD_LENGTH 50

int main(int argc, char** argv) {

    int i = 0, j = 0, k = 0, count = 0, word_count = 0;
    char buffer[BUFFER_SIZE];
    char words[WORD_LENGTH][BUFFER_SIZE];
    char c;
    FILE* fp;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Reading file %s...\n", argv[1]);

    while ((c = fgetc(fp)) != EOF) {

        if (isalpha(c)) {
            buffer[i++] = c;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                strcpy(words[j++], buffer);
                i = 0;
                count++;
            }
        }

        if (j == WORD_LENGTH - 1) {
            printf("Error: too many words in file\n");
            exit(EXIT_FAILURE);
        }

    }

    fclose(fp);

    word_count = count;

    printf("%d words found in file %s\n", word_count, argv[1]);

    return 0;

}