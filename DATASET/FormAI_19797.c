//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // check if a filename is provided as argument
    if(argc != 2) {
        printf("Please provide a filename as argument.\n");
        return 0;
    }

    // open the file
    FILE *file = fopen(argv[1], "r");

    // check if the file exists
    if(file == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    int wordCount = 0;
    int charCount = 0;
    char c;

    // loop through the file character by character
    while((c = fgetc(file)) != EOF) {
        // if the character is a letter, add it to the character count
        if(isalpha(c)) {
            charCount++;
        }
        // if the character is a space, increase the word count
        else if(c == ' ') {
            wordCount++;
        }
    }
    
    // add the last word as the loop ended
    wordCount++;

    // print the results
    printf("The file %s has %d words and %d characters.\n", argv[1], wordCount, charCount);

    // close the file
    fclose(file);

    return 0;
}