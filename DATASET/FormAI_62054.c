//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// function to count the number of words in a given string
int countWords(char *str) {
    int count = 0;
    bool isWord = false;
    
    // loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // if the current character is not a whitespace
        if (!isspace(str[i])) {
            // if we haven't already started counting a word
            if (!isWord) {
                isWord = true;
                count++;
            }
        } else {
            // set isWord to false if we encounter a whitespace
            isWord = false;
        }
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // remove the newline character from the end of the string
    str[strlen(str)-1] = '\0';
    
    // call the countWords function to get the number of words in the string
    int numWords = countWords(str);
    
    // print the result
    printf("The string \"%s\" contains %d words.\n", str, numWords);
    
    return 0;
}