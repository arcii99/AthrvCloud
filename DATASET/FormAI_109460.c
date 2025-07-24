//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    // check if file argument is provided
    if (argc < 2) {
        printf("Please provide a file as an argument.\n");
        return 1;
    }

    // open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // initialize word count to 0
    int count = 0;
    
    // initialize character and word arrays
    char c;
    char word[MAX_WORD_LENGTH];

    // initialize frequency array to 0
    int frequency[26] = {0};

    // loop through file
    while ((c = fgetc(fp)) != EOF) {
        // check if character is a letter
        if (isalpha(c)) {
            // convert to lowercase and add to word
            c = tolower(c);
            word[count++] = c;
        } else {
            // end of word
            if (count > 0) {
                // null terminate word
                word[count] = '\0';

                // reset count
                count = 0;

                // calculate frequency
                frequency[word[0] - 'a']++;
            }
        }
    }

    // close file
    fclose(fp);

    // print frequency of each letter
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }

    return 0;
}