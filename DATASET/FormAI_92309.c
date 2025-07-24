//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000 
#define MAX_COMPRESSED_SIZE 500

char* compress(char* input); // function prototype

int main() {
    char* input_string = malloc(MAX_STRING_SIZE*sizeof(char)); // allocate memory for input string
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_SIZE, stdin);
    printf("Compressed string: %s", compress(input_string)); // call compress function and print compressed string
    free(input_string); // free memory
    return 0;
}

char* compress(char* input) {
    int count = 1; // initialize count
    char current_char = input[0]; // initialize current character
    char* compressed_string = malloc(MAX_COMPRESSED_SIZE*sizeof(char)); // allocate memory for compressed string
    int index = 0; // initialize index

    for(int i=1; i<=strlen(input); i++) { // loop through input string
        if(input[i] == current_char) { // if current character is equal to next character
            count++; // increment count
        } else { // if current character is not equal to next character
            compressed_string[index++] = current_char; // add current character to compressed string
            compressed_string[index++] = count + '0'; // add count as a character to compressed string
            current_char = input[i]; // set current character to next character
            count = 1; // reset count
        }
    }

    compressed_string[index] = '\0'; // append null character to end of compressed string
    return compressed_string; // return compressed string
}