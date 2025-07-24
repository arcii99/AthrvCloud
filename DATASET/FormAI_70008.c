//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char filename[50], word[50];
    int count = 0;
    FILE *fp;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("\nEnter the word to count: ");
    scanf("%s", word);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.");
        return 0;
    }

    char currentWord[50];
    while (fscanf(fp, "%s", currentWord) != EOF) {
        if (strcmp(currentWord, word) == 0) {
            count++;
        }
    }

    printf("\nThe frequency of the word %s in the file %s is %d\n", word, filename, count);

    fclose(fp);

    return 0;
}