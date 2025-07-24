//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];       // character array to store user input
    char output[100];      // character array to store output

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);   // read user input

    // convert each character to lowercase and store in output array
    for(int i=0; i<strlen(input); i++) {
        output[i] = tolower(input[i]);
    }

    // remove all punctuation marks from output array
    for(int i=0, j=0; i<strlen(output); i++) {
        if(isalpha(output[i]) || isspace(output[i])) {
            output[j] = output[i];
            j++;
        }
    }

    // print the processed output
    printf("\nProcessed text: %s\n", output);

    return 0;
}