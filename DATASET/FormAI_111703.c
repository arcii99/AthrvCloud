//FormAI DATASET v1.0 Category: Word Count Tool ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_SIZE 50

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error: Please provide a filename\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char current_word[MAX_WORD_SIZE];    // buffer to store the current word
    int current_word_size = 0;           // size of the current word (in characters)
    int word_count = 0;                  // total number of words in the file
    
    while(1) {
        char c = fgetc(fp);              // read one character from the file
        
        // If we reach the end of file
        if(feof(fp)) {
            if(current_word_size > 0) {  // if there is a word in the buffer
                word_count++;           // count it
            }
            break;
        }
        
        // If the current character is not a whitespace
        if(!isspace(c)) {
            // Add the character to the buffer
            current_word[current_word_size++] = c;
            if(current_word_size >= MAX_WORD_SIZE) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
        }
        else {                          // We have reached the end of the word
            if(current_word_size > 0) { // If the word is non-empty
                word_count++;           // count it
                current_word_size = 0;  // reset the buffer
                memset(current_word, 0, sizeof(current_word));
            }
        }
    }

    printf("Total number of words in %s: %d\n", argv[1], word_count);
    
    fclose(fp);
    return 0;
}