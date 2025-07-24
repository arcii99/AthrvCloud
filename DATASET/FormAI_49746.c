//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

/**
 * A simple compression algorithm that replaces
 * repeated characters with a count of how many times
 * they appear in a row.
 * For example, "aaaabbbcc" would be compressed to "4a3b2c"
 */

void compress(char *input) {
    //initialize variables
    char output[MAX_LEN];
    memset(output, 0, MAX_LEN);
    int len = strlen(input);
    int count = 1;
    int k = 0;

    //iterate through the input string
    for(int i=0; i<len; i++) {
        if(input[i] == input[i+1]) {
            //if a character is repeated, increase the count
            count++;
        }
        else {
            //else add the count and character to the output
            output[k] = count + '0';
            output[k+1] = input[i];
            k += 2;
            //reset the count
            count = 1;
        }
    }
    //copy the compressed string back to the input string
    strcpy(input, output);
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string to compress:\n");
    fgets(input, MAX_LEN, stdin);
    //strip the newline character from the input
    input[strcspn(input, "\n")] = 0;
    //convert string to all lowercase
    for(int i=0; i<strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    compress(input);
    printf("Compressed string: %s\n", input);
    return 0;
}