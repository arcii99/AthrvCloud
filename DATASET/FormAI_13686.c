//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // variables to store input and output
    char input[100];
    char output[100];
    
    // prompt the user to enter text
    printf("Enter some text: ");
    fflush(stdout);
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0'; // remove newline char

    // convert each character in input to uppercase and store in output
    for (int i = 0; i < strlen(input); i++) {
        output[i] = toupper(input[i]);
    }
    
    // print the input and output
    printf("\nInput: %s\n", input);   
    printf("Output: %s\n", output);
    
    // prompt the user to enter a character to search for
    printf("\nEnter a character to search for: ");
    fflush(stdout);
    char c = getchar();
    getchar(); // consume the newline char
    
    // count the number of times the character appears in the input
    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == c) {
            count++;
        }
    }
    
    // print the result
    printf("\nCharacter '%c' appears %d times in the input.\n", c, count);

    return 0;
}