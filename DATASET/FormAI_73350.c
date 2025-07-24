//FormAI DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[1000]; // we'll assume no more than 1000 characters.
    int count = 0;  
    
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin); // read the string

    // starting with a space is a good way to make sure the first word is counted
    // also helps properly-count hyphenated words
    strcat(string, " ");

    // iterate through the string
    for (int i = 0; i < strlen(string) - 1; i++) {
        if (string[i] == ' ' && string[i+1] != ' ') { // we found a word!
            count++; // increase the word count
        }
    }
    
    printf("Word count: %d\n", count); // print the count
    
    return 0;
}