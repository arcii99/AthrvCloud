//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scalable
/* 
 * This program is a simple implementation of a compression algorithm
 * using run-length encoding technique. It takes an input string and
 * returns a compressed version of that string.
 */

#include<stdio.h>
#include<string.h>

char* compress(char* input) {
    int len = strlen(input);

    // Allocate memory for output string.
    char* output = (char*) calloc(len * 2 + 1, sizeof(char));

    int i = 0, j = 0, count = 1;
    char prev = input[0];

    // Loop through the input string and count the occurrences of each character.
    for(i = 1; i < len; i++) {
        if(input[i] == prev) {
            count++;
        } else {
            // Append the character and its count to the output string.
            output[j++] = prev;
            sprintf(output + j, "%d", count);
            j = strlen(output);
            prev = input[i];
            count = 1;
        }
    }

    // Append the last character and its count to the output string.
    output[j++] = prev;
    sprintf(output + j, "%d", count);

    return output;
}

int main() {
    char input[] = "aaabbcccdddeeeeffff";
    char* compressed = compress(input);

    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", compressed);

    return 0;
}