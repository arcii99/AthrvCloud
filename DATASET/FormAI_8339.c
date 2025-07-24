//FormAI DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// The maximum size of the input string.
#define MAX_SIZE 100

// Main function.
int main() {

    // Initialize the input string.
    char input[MAX_SIZE];

    // Take input from the user.
    printf("Enter the string to be compressed: ");
    fgets(input, MAX_SIZE, stdin);

    // Initialize the output string.
    char output[MAX_SIZE] = "";

    // Initialize the pointer variables.
    char *ptr1 = input, *ptr2 = input;

    // Initialize the frequency count.
    int count = 0;

    // Loop through the input string.
    while(*ptr1 != '\0') {

        // If the characters at the two pointers are the same...
        if(*ptr1 == *ptr2) {

            // ...then increment the frequency count.
            count++;

            // ...and move the second pointer.
            ptr2++;

        } else {

            // If the characters at the two pointers are different, then
            // add the current character and its frequency to the output string.
            char temp[MAX_SIZE];
            sprintf(temp, "%c%d", *ptr1, count);
            strcat(output, temp);

            // Reset the frequency count to 1.
            count = 1;

            // Reset the second pointer to the first pointer.
            ptr2 = ptr1;

        }

        // Move the first pointer.
        ptr1++;

    }

    // Add the last character and its frequency to the output string.
    char temp[MAX_SIZE];
    sprintf(temp, "%c%d", *ptr1, count);
    strcat(output, temp);

    // Print the compressed string.
    printf("Compressed string: %s\n", output);

    // Return 0 to indicate successful program execution.
    return 0;

}