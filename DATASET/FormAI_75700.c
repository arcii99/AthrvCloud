//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of input string
#define MAX_CODE_SIZE 100 // Maximum size of compressed code

char compressedCode[MAX_CODE_SIZE]; // Global variable to store compressed code

// Recursive function to compress a string using Run length encoding algorithm
void compress(char *str, int index, int count) {
    // Base case
    if (index == strlen(str)) {
        compressedCode[count] = '\0'; // Set null character at end of compressed code
        return;
    }

    int i;
    for (i = index + 1; i < strlen(str); i++) {
        if (str[i] != str[index]) {
            if (count == 1) {
                compressedCode[count - 1] = str[index];
                compress(str, i, count + 1);
                return;
            } else if (count > 1) {
                compressedCode[count - 1] = str[index];
                char countStr[MAX_SIZE];
                sprintf(countStr, "%d", count);
                strcat(compressedCode, countStr);
                compress(str, i, 1);
                return;
            }
        }
        count++;
    }
    if (count == 1) {
        compressedCode[count - 1] = str[index];
        compress(str, i, count + 1);
        return;
    } else if (count > 1) {
        compressedCode[count - 1] = str[index];
        char countStr[MAX_SIZE];
        sprintf(countStr, "%d", count);
        strcat(compressedCode, countStr);
        compress(str, i, 1);
        return;
    }
}

// Main function
int main() {
    char str[MAX_SIZE];
    printf("Enter input string to be compressed: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline from input string
  
    compress(str, 0, 1);
  
    printf("Compressed code: %s\n", compressedCode);
  
    return 0;
}