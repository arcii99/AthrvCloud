//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

/*
* This is a simple example program of a unique Compression algorithm in C language.
* The algorithm works by compressing a string to its Morse code representation.
* It uses a lookup table to match each character to its Morse code
* By doing this, the size of the original string is reduced
*/


struct morse_code {
    char character;
    char * code;
};

// Initialize the lookup table
struct morse_code lookup_table[] = {
    {'A', ".-" }, {'B', "-..." }, {'C', "-.-." }, {'D', "-.." }, {'E', "." }, 
    {'F', "..-." }, {'G', "--." }, {'H', "...." }, {'I', ".." }, {'J', ".---" }, 
    {'K', "-.-" }, {'L', ".-.." }, {'M', "--" }, {'N', "-." }, {'O', "---" }, 
    {'P', ".--." }, {'Q', "--.-" }, {'R', ".-." }, {'S', "..." }, {'T', "-" }, 
    {'U', "..-" }, {'V', "...-" }, {'W', ".--" }, {'X', "-..-" }, {'Y', "-.--" }, 
    {'Z', "--.." }, {'0', "-----" }, {'1', ".----" }, {'2', "..---" }, {'3', "...--" }, 
    {'4', "....-" }, {'5', "....." }, {'6', "-...." }, {'7', "--..." }, {'8', "---.." }, 
    {'9', "----." }, {' ', " "},
}; 

// Function that compresses the input string to Morse code
void compress_string(char *input_string, char *compressed_string) {
    int i, j;
    char *code;
    for (i = 0; input_string[i] != '\0'; i++) {
        code = "";
        for (j = 0; j < sizeof(lookup_table)/sizeof(struct morse_code); j++) {
            if (input_string[i] == lookup_table[j].character) {
                code = lookup_table[j].code;
                break;
            }
        }
        strcat(compressed_string, code);
    }
}

// Main function
int main() {
    char input_string[MAX_LEN];
    char compressed_string[MAX_LEN];
    printf("Enter a string to compress:");
    fgets(input_string, MAX_LEN, stdin);
    // Remove the trailing newline character from the input string
    input_string[strcspn(input_string, "\n")] = 0;
    // Compress the string to Morse code
    compress_string(input_string, compressed_string);
    printf("Original string: %s\n", input_string);
    printf("Compressed string: %s\n", compressed_string);
    return 0;
}