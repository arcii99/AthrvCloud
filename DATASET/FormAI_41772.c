//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
/*Program to count the frequency of each word in a text file*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

int main(int argc, char **argv) {
    char word[MAX_WORDS][WORD_LENGTH];
    int count[MAX_WORDS];
    char buffer;
    int i = 0, j = 0, wordCount = 0;

    // Open the file in read mode
    FILE *fp = fopen("input.txt", "r");

    // Check if file exists
    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    // Read the file character by character
    while ((buffer = fgetc(fp)) != EOF) {
        if (isalpha(buffer)) {
            word[i][j++] = tolower(buffer);
        }
        // If the character is space or newline, end of word
        else if (isspace(buffer)) {
            word[i][j] = '\0';
            // Check if this word already exists in the list
            int exists = 0;
            for (int k = 0; k < wordCount; k++) {
                if (strcmp(word[i], word[k]) == 0) {
                    exists = 1;
                    count[k]++;
                    break;
                }
            }
            if (!exists) {
                strcpy(word[wordCount], word[i]);
                count[wordCount++] = 1;
            }
            // Reset word index
            j = 0;
            i++;
        }
    }
    fclose(fp);

    // Print the frequency of each word
    printf("Word\tFrequency\n");
    for (int k = 0; k < wordCount; k++)
        printf("%s\t%d\n", word[k], count[k]);

    return 0;
}