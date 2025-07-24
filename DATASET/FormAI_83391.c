//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char* str) {
    int i, j;
    char temp[strlen(str)+1]; // Create a temporary string that is the same length as the input string

    for(i = 0, j = 0; i < strlen(str); i++) {
        if(isalnum(str[i])) {
            temp[j] = str[i]; // If the character is alphanumeric, add it to the temporary string
            j++;
        }
    }
    temp[j] = '\0'; // Add null terminator to the end of the temporary string

    strcpy(str, temp); // Copy the temporary string back into the input string
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Get user input

    sanitizeInput(str); // Sanitize input

    printf("Sanitized string: %s", str);

    return 0;
}