//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp; // file pointer
    char filename[20]; // name of the file
    char line[200]; // the line in the file
    int v_count = 0; // count of lines containing the letter 'v'
    int i_count = 0; // count of lines containing the letter 'i'
    int love_count = 0; // count of lines containing the word 'love'
    int total_count = 0; // total count of lines in the file

    printf("Oh my dearest, please tell me the name of the file you want to analyze: ");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // reading mode

    if (fp == NULL) {
        printf("I'm so sorry my love, cannot open the file %s.", filename);
        exit(EXIT_FAILURE);
    }

    printf("\nMy sweet, here is the analysis of the file: \n");

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "v") != NULL) {
            v_count++;
        }
        if (strstr(line, "i") != NULL) {
            i_count++;
        }
        if (strstr(line, "love") != NULL) {
            love_count++;
        }
        total_count++;
    }

    printf("\nMy angel, there are %d lines in the file %s.\n", total_count, filename);
    printf("\nMy love, the letter 'v' appears in %d lines in the file %s.\n", v_count, filename);
    printf("\nMy sweetheart, the letter 'i' appears in %d lines in the file %s.\n", i_count, filename);
    printf("\nMy dearest, the word 'love' appears in %d lines in the file %s.\n", love_count, filename);

    fclose(fp); // closing the file

    return 0;
}