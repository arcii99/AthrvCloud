//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[50];
    int i;

    printf("Please enter a string: ");
    fgets(input, 50, stdin); // get user input and save it in input array

    // Check if input contains any non-alphabetic characters
    for(i = 0; input[i] != '\0'; i++) {
        if(!isalpha(input[i])) {
            printf("Input contains non-alphabetic characters.\n");
            return 1; // exit program with error code
        }
    }

    // Check if input is all uppercase
    for(i = 0; input[i] != '\0'; i++) {
        if(islower(input[i])) {
            printf("Input contains lowercase characters.\n");
            return 1; // exit program with error code
        }
    }

    printf("Input is valid.\n");

    return 0; // exit program with success code
}