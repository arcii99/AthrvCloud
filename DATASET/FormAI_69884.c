//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a C data recovery tool example program */

int main() {
    FILE *fp;
    char file_name[100], content[100], c;
    int i = 0, j = 0, len = 0;

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", &file_name);

    // Open file for reading
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read file content
    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ' || c == '\n') { // end of word
            content[i] = '\0'; // terminate word
            i = 0;

            // Reverse the word
            for (j = 0, len = strlen(content) - 1; j < len; j++, len--) {
                content[j] ^= content[len];
                content[len] ^= content[j];
                content[j] ^= content[len];
            }

            // Print the word
            printf("%s ", content);
        } else { // add character to word
            content[i++] = c;
        }
    }

    // Close file
    fclose(fp);

    return 0;
}