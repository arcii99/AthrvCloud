//FormAI DATASET v1.0 Category: Word Count Tool ; Style: calm
/* This program counts the number of words in a given text file */

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char fileName[100], ch;
    int wordCount = 0, inWord = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            wordCount++;
        }
    }

    printf("The word count in the given text file is: %d\n", wordCount);
    fclose(file);
    return 0;
}