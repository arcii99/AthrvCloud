//FormAI DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    // Allocate memory for a string
    char *str = (char*) malloc(100 * sizeof(char));

    // Get user input
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverse_string(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Free allocated memory
    free(str);

    return 0;
}