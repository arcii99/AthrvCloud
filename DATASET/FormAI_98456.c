//FormAI DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress a given string
int compress(char* input, char* output) {
    int count = 1; // counter to count the frequency of each letter
    char prev = *input; // current character
    int len = strlen(input); // length of the input string
    int index = 0; // index of the output string

    // loop through the input string
    for(int i = 1; i < len; i++) {
        // if the current character is the same as the previous one
        if(input[i] == prev) {
            count++; // increment the counter
        }
        else {
            // append the previous character and its frequency to the output string
            output[index++] = prev; 
            output[index++] = count + '0';
            prev = input[i]; // reset the previous character
            count = 1; // reset the counter
        }
    }
    // append the last character and its frequency to the output string
    output[index++] = prev;
    output[index++] = count + '0';
    output[index] = '\0'; // terminate the output string with a null character
    return strlen(output); // return the length of the output string
}

int main() {
    char input[100], output[100];
    printf("Enter a string to compress: ");
    scanf("%s", input);
    int len = compress(input, output);
    printf("Compressed string: %s\n", output);
    printf("Length of compressed string: %d\n", len);
    return 0;
}