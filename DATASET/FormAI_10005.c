//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************
 * This program implements a unique digital watermarking   *
 * algorithm in an irregular style. The algorithm involves *
 * randomly inserting characters into a string in a way    *
 * that can be detected but not easily removed.             *
 *                                                          *
 * Note that this program is for demonstration purposes    *
 * only and not intended for serious use.                   *
 ************************************************************/

/* Function prototypes */
void watermark(char *str, char *mark);
void extract_mark(char *str, char *mark);

int main() {
    /* Define input strings */
    char str[] = "The quick brown fox jumps over the lazy dog.";
    char mark[] = "Watermark";

    /* Call the watermark function */
    watermark(str, mark);

    /* Print the marked string */
    printf("Marked string: \n%s\n", str);

    /* Extract the mark from the marked string */
    extract_mark(str, mark);

    /* Print the extracted mark */
    printf("Extracted mark: \n%s\n", mark);

    return 0;
}

/* Function to insert the mark into the string */
void watermark(char *str, char *mark) {
    int len_str = strlen(str);
    int len_mark = strlen(mark);
    int i, j;

    /* Insert the mark into the string */
    for (i = 0; i < len_mark; i++) {
        /* Generate a random position for the character */
        j = rand() % len_str;

        /* Insert the character at the random position */
        str[j] = mark[i];
    }
}

/* Function to extract the mark from the marked string */
void extract_mark(char *str, char *mark) {
    int len_str = strlen(str);
    int len_mark = strlen(mark);
    int i, j, k;

    /* Loop through the string to find the mark */
    for (i = 0; i < len_str - len_mark; i++) {
        /* Check if this substring matches the mark */
        if (strncmp(str + i, mark, len_mark) == 0) {
            /* Remove the mark from the string */
            for (j = i; j < i + len_mark; j++) {
                /* Generate a random character to insert */
                k = rand() % 26;
                str[j] = 'a' + k;
            }

            /* Exit the loop */
            break;
        }
    }
}