//FormAI DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() {
    char filename[MAX_LEN];
    printf("Enter the filename to be read: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Failed to open file %s. Exiting...\n", filename);
        exit(1);
    }

    char ch;
    int num_chars = 0, num_words = 0, num_lines = 0;
    while((ch = fgetc(fp)) != EOF) {
        num_chars++;
        if(ch == ' ' || ch == '\n' || ch == '\t') {
            num_words++;
        }
        if(ch == '\n') {
            num_lines++;
        }
    }

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words + 1);
    printf("Number of lines: %d\n", num_lines + 1);

    fclose(fp);
    return 0;
}