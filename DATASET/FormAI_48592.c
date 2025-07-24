//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program takes in a string of text and prints out the longest word in the string */

int main() {
    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);
    char *token = strtok(text, " ");  // tokenize the text by space
    char longest_word[50] = "";  // initialize the longest_word variable
    int max_len = 0; // initialize the maximum length variable
   
    while (token != NULL) {
        int len = strlen(token);
        if (len > max_len) {  // if the length of the current word is greater than the maximum length so far
            max_len = len;
            strcpy(longest_word, token);  // copy the word into longest_word variable
        }
        token = strtok(NULL, " ");
    }
    printf("The longest word in the text is: %s\n", longest_word);
    return 0;
}