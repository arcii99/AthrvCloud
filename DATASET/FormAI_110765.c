//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
//Ken Thompson Style Unique C Compression Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000    // Maximum size of input string

char *compress(char *str);

// This function will take a string and return the compressed string
char *compress(char *str) {
    int i, cnt = 1, j = 0;
    int len = strlen(str);
    char *compress_str = (char *) malloc(len * sizeof(char));
    
    // Loops through the string and checks for repeated characters
    for(i = 0; i < len; i++) {
        if(str[i] == str[i+1]) {
            cnt++;
        }
        else {
            if(cnt > 1) {
                // Add the count to the compressed string
                compress_str[j++] = cnt + '0';
            }
            // Add the character to the compressed string
            compress_str[j++] = str[i];
            cnt = 1;
        }
    }
    // Add the null terminator to the compressed string
    compress_str[j] = '\0';
    return compress_str;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter the string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;    // Removes the newline character from input
    
    // Call the compress function and print the compressed string
    char *compressed_str = compress(str); 
    printf("The compressed string is: %s", compressed_str);
    free(compressed_str);   // Free the dynamically allocated memory
    return 0;
}