//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100]; // initialize input buffer
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin); // get user input and store in input buffer
    
    char output[100]; // initialize output buffer
    int outputIndex = 0;
    for(int i=0; i< strlen(input); i++) {
        char current = input[i];
        if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
            output[outputIndex] = current; // add vowel to output buffer
            outputIndex++;
        }
    }
    
    printf("Vowels found: %s", output); // print the vowels found in the input
    
    return 0;
}