//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100000

int main(int argc, char *argv[]) {
    char *filename;
    int num_words = 0, num_unique_words = 0, i, j, found;
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], word[MAX_WORD_LENGTH], c;
    FILE *fp;

    // Check if file name provided
    if(argc < 2) {
        printf("Error: File name not provided\n");
        return 1;
    }

    // Get file name from arguments
    filename = argv[1];

    // Open file for reading
    fp = fopen(filename, "r");

    // Check if file opened successfully
    if(fp == NULL) {
        printf("Error: Unable to open file: %s\n", filename);
        return 1;
    }

    // Read words from file
    while((c = fgetc(fp)) != EOF) {
        if(isalpha(c)) {
            word[strlen(word)] = tolower(c);
        } else if(strlen(word) > 0) {
            word[strlen(word)] = '\0';
            num_words++;

            // Check if word already exists
            found = 0;
            for(i = 0; i < num_unique_words; i++) {
                if(strcmp(words[i], word) == 0) {
                    found = 1;
                    break;
                }
            }

            // Add new word to array and increment unique word count
            if(!found) {
                strcpy(words[num_unique_words], word);
                num_unique_words++;
            }

            // Reset word buffer
            memset(word, 0, MAX_WORD_LENGTH);
        }
    }

    // Close file
    fclose(fp);

    // Print word frequency count
    printf("Word Frequency Count:\n");
    for(i = 0; i < num_unique_words; i++) {
        int count = 0;
        for(j = 0; j < num_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        printf("%-15s%5d\n", words[i], count);
    }

    return 0;
}