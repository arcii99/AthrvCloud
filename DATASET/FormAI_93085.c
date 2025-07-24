//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void paranoidCopy(char *dest, const char *src, size_t destSize) {
    size_t srcLength = strlen(src);

    if (srcLength >= destSize) {
        // Source string is longer than destination string, truncate it
        srcLength = destSize - 1;
    }

    // Copy the string one char at a time
    for (size_t i = 0; i < srcLength; i++) {
        char currentChar = src[i];

        // Check if the current char is printable, if not, replace it with a "*"
        if (!isprint(currentChar)) {
            currentChar = '*';
        }

        // Check if the destination buffer has enough space for the current char
        if (i + 1 >= destSize) {
            // Not enough space, truncate the string
            break;
        }

        dest[i] = currentChar;
    }

    // Add null terminator
    dest[srcLength] = '\0';
}

int main() {
    char input[MAX_STRING_LENGTH];
    char paranoid[MAX_STRING_LENGTH];

    printf("Enter a string to copy: ");
    fgets(input, MAX_STRING_LENGTH, stdin);

    paranoidCopy(paranoid, input, MAX_STRING_LENGTH);

    printf("Original string: %s\n", input);
    printf("Paranoid string: %s\n", paranoid);

    return 0;
}