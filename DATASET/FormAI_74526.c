//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000]; // maximum input message length
    int wordCount = 0; // initialize word count to 0
    
    printf("Enter a message: "); // prompt user for input
    fgets(input, 1000, stdin); // get input message and store in input
    
    // loop through input message, counting words
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            wordCount++; // increment word count for each space found
        }
    }
    
    // print word count
    printf("\nWord count: %d\n", wordCount + 1); // add 1 to word count to account for final word after last space
    
    return 0; // exit program
}