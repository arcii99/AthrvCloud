//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000], output[1000]; // declare string variables to store input and output
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // get input from user
    int len = strlen(input); // calculate length of input string
    int j = 0; // initialize variable to keep track of output index

    for (int i = 0; i < len; i++) { // loop through each character of input string
        if (input[i] >= 'a' && input[i] <= 'z') { // check if the character is lowercase
            output[j] = input[i] - 32; // convert the lowercase character to uppercase by subtracting 32 from its ASCII code
            j++; // increment output index
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') { // check if the character is already uppercase
            output[j] = input[i]; // keep the character as is
            j++; // increment output index
        }
        // ignore all other characters like numbers, special characters, etc.
    }

    output[j] = '\0'; // add null terminator to the end of output string to mark the end of the string
    printf("Output: %s", output); // display the output string

    return 0;
}