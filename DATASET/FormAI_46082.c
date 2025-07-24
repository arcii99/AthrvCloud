//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int count = 0, in_word = 0;
    
    printf("Enter a sentence:\n");
    fgets(input, 100, stdin); // get input from user
    
    for(int i = 0; input[i] != '\0'; i++) {
        if(isalpha(input[i])) { // if current character is alphabetic
            if(in_word == 0) { // if we were not in a word previously
                count++; // increment word count
                in_word = 1; // set flag to indicate we are in a word
            }
        }
        else { // if current character is not alphabetic
            in_word = 0; // set flag to indicate we are not in a word
        }
    }
    
    printf("Word count: %d\n", count); // output word count
    
    return 0;
}