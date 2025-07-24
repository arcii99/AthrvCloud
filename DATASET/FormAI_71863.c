//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc != 2) { // check if file name is provided
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); // open file

    if (file == NULL) { // check if file is valid
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int word_count = 0;
    int in_word = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {

        if (isspace(c)) { // found whitespace, so not in word anymore
            in_word = 0;
        } else if (in_word == 0) { // whitespace before word, increase count
            in_word = 1;
            word_count++;
        }
    }

    printf("The file %s contains %d words.\n", argv[1], word_count);

    fclose(file); // close file
    return 0;
}