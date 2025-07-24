//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A cheerful compression algo that replaces consecutive numbers with //
// the number followed by '!' and its count. For example 333222111000 //
// will be converted to 3!3 3!2 1!3 0!3 //
char *compress(char *input) {
    int length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * length * 2); // Allocate enough memory to store the output
    int i = 0, j = 0, count = 1;
    while (i < length) {
        if (input[i] == input[i+1]) { // if the current letter is the same as the next one
            count++; // increase the count
        } else {
            // add the current letter followed by its count
            output[j++] = input[i];
            sprintf(&output[j], "%d!", count); // convert the count to a string and add '!'
            j = strlen(output); // move the index to the end of the output
            count = 1; // reset the count
        }
        i++; // move to the next letter
    }
    return output;
}

int main() {
    char input[] = "333222111000";
    char *output = compress(input);
    printf("Original String: %s\n", input);
    printf("Compressed String: %s\n", output);
    free(output); // remember to free the memory allocated by malloc
    return 0;
}