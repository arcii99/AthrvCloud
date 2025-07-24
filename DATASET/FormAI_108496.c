//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress string
char* compressString(char* str) {

    int len = strlen(str);
    char* compressedStr = (char*)malloc(sizeof(char) * (len + 1));

    // Base case for empty string
    if (len == 0) {
        return "";
    }

    // Counting consecutive repetitions of characters and adding them to compressed string
    int count = 1, j = 0;
    compressedStr[j++] = str[0];
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        }
        else {
            compressedStr[j++] = count + '0';
            count = 1;
            compressedStr[j++] = str[i];
        }
    }
    compressedStr[j++] = count + '0';
    compressedStr[j] = '\0';

    // Return the compressed string if it is shorter than the original, otherwise return the original string
    return (strlen(compressedStr) < len) ? compressedStr : str;
}

int main() {

    char inputStr[50];
    printf("Enter a string: ");
    scanf("%s", inputStr);

    char* compressedStr = compressString(inputStr);
    printf("Compressed string: %s\n", compressedStr);

    return 0;
}