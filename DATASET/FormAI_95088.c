//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Convert all letters to lowercase
    for (int i=0; i<strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += ('a'-'A');
        }
    }

    // Remove all vowels from string
    int j=0;
    char result[100];
    for (int i=0; i<strlen(input); i++) {
        if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u') {
            result[j] = input[i];
            j++;
        }
    }
    result[j] = '\0';

    printf("Output: %s", result);
    return 0;
}