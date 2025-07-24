//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int charCount = 0, lineCount = 0, wordCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != '\n') {
            charCount++;
        }
        if (ch == ' ' || ch == '\n') {
            wordCount++;
        }
        if (ch == '\n') {
            lineCount++;
        }
    }

    printf("Number of characters in the file: %d\n", charCount);
    printf("Number of words in the file: %d\n", wordCount);
    printf("Number of lines in the file: %d\n", lineCount);

    fclose(fp);

    return 0;
}