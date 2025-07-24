//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

// function to compress the given string using custom compression algorithm
char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*) malloc(sizeof(char) * len);
    int k = 0; // pointer to track current index of compressed string
    for (int i = 0; i < len; i++) {
        int count = 1; // count of consecutive similar characters
        while (i < len - 1 && str[i] == str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            compressed[k++] = str[i-1]; // append the repeated character
            compressed[k++] = count + '0'; // append the count as a digit
        } else {
            compressed[k++] = str[i]; // append single character as it is
        }
    }
    compressed[k] = '\0'; // add null terminator to the compressed string
    return compressed;
}

int main() {
    char str[MAX_LEN];
    printf("Enter the string to be compressed: ");
    fgets(str, MAX_LEN, stdin);
    // remove the newline character from the input string
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    char* compressed = compress(str);
    printf("The compressed string is: %s\n", compressed);
    free(compressed);
    return 0;
}