//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
/* This C Word Count Tool program counts the number of words in an input file. */

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main(int argc, char *argv[]) {
    FILE *input_file;
    int words[MAX_WORD_LENGTH];
    int c, i, length, max_length, max_count;

    /* Validate Command Line Input */
    if (argc != 2) {
        printf("Error: Invalid Usage. Please enter filename as single argument.\n");
        return 1;
    }

    /* Attempt to Open the File */
    if ((input_file = fopen(argv[1], "r")) == NULL) {
        printf("Error: File Not Found.\n");
        return 1;
    }

    /* Count the Words */
    max_length = max_count = 0;
    length = 0;
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        words[i] = 0;
    }

    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            ++length;

            if (length > MAX_WORD_LENGTH) {
                length = MAX_WORD_LENGTH;
            }
        }
        else if (length != 0) {
            ++words[length - 1];

            if (words[length - 1] > max_count) {
                max_count = words[length - 1];
                max_length = length;
            }

            length = 0;
        }
    }

    /* Display the Results */
    printf("%-10s %10s\n", "Length", "Frequency");
    printf("------------------------------\n");
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        if (words[i] != 0) {
            printf("%-10d %10d\n", i + 1, words[i]);
        }
    }

    printf("------------------------------\n");
    printf("Most Frequent Length: %d (%d occurrences)\n", max_length, max_count);

    /* Close the File */
    fclose(input_file);

    return 0;
}