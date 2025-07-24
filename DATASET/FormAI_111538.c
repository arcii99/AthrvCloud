//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100]; // Declare a char array to store the input string
    printf("Enter a string: ");
    fgets(str, 100, stdin); // Read input string from user

    int length = strlen(str); // Get the length of the string

    // Replace all vowels with '*'
    for (int i=0; i<length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = '*';
        }
    }

    printf("Processed string: %s", str); // Print the processed string
    return 0;
}