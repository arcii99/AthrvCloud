//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

char* compress(char* str);

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string to compress: ");
    scanf("%[^\n]", str);
    char* compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str); // free memory to avoid memory leaks
    return 0;
}

char* compress(char* str) {
    int len = strlen(str);
    char* compressed_str = malloc((len + 1) * sizeof(char)); // allocate memory to store compressed string
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) { // if current character is a letter
            compressed_str[index++] = tolower(str[i]); // add lowercase version of character to compressed string
        } else if (isdigit(str[i])) { // if current character is a digit
            int count = str[i] - '0'; // get the count of repetitions of previous character
            while (count > 1) { // add count - 1 copies of previous character to compressed string
                compressed_str[index++] = compressed_str[index-2];
                count--;
            }
        } else { // if current character is not a letter or digit, ignore it
            continue;
        }
    }
    compressed_str[index] = '\0'; // add null terminator to compressed string
    return compressed_str;
}