//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to translate the input string into alien language
void translate(char input[]) {
    int length = strlen(input);
    char output[length+1];
    for(int i=0; i<length; i++) {
        // Replacing 'c' with 'x'
        if(input[i] == 'c') {
            output[i] = 'x';
        }
        // Replacing 'e' with 'z'
        else if(input[i] == 'e') {
            output[i] = 'z';
        }
        // Replacing 't' with 'v'
        else if(input[i] == 't') {
            output[i] = 'v';
        }
        else {
            output[i] = input[i];
        }
    }
    output[length] = '\0';
    printf("\nTranslated string: %s\n", output);
}

int main() {
    printf("\nWelcome to the Alien Language Translator!\n");
    printf("\nEnter the string to be translated: ");
    
    char input[100];
    fgets(input, 100, stdin);

    // Removing the newline character '\n' at the end of the input string
    input[strlen(input)-1] = '\0';
    
    // Calling the translate function to translate the input string
    translate(input);
    
    return 0;
}