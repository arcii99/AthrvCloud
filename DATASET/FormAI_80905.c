//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main() {

    char *text = malloc(sizeof(char) * MAX_LEN);
    char *compressed_text = malloc(sizeof(char) * MAX_LEN);

    printf("Enter the text to be compressed:\n");
    fgets(text, MAX_LEN, stdin);

    int text_len = strlen(text) - 1; // Deducting newline character

    int i, j, count;
    for(i = 0, j = 0; i < text_len; i++) {

        count = 1; // Initialize count to 1
        while(text[i] == text[i+1]) { // Checking for repeated characters
            i++;
            count++;
        }

        if(count > 1) { // More than one occurrences of the character
            compressed_text[j++] = text[i]; // Store the character
            compressed_text[j++] = count + '0'; // Convert count to character and store
        }
        else {
            compressed_text[j++] = text[i];
        }
    }
    compressed_text[j] = '\0'; // Null terminate the compressed string

    printf("\nThe compressed text is:\n%s\n", compressed_text);

    free(text);
    free(compressed_text);

    return 0;
}