//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", input_string);
 
    int length = strlen(input_string), i;
    char inverted_string[length];

    // Invert the string character by character 
    for (i = length - 1; i >= 0; i--) {
        inverted_string[length - i - 1] = input_string[i];
    }

    // Convert string to uppercase
    char uppercase_string[length];
    for (i = 0; i < length; i++) {
        uppercase_string[i] = toupper(input_string[i]);
    }

    // Remove all vowels from the string
    char consonant_string[length];
    int j = 0;
    for (i = 0; i < length; i++) {
        if (input_string[i] != 'a' && input_string[i] != 'A' && input_string[i] != 'e' && input_string[i] != 'E' && input_string[i] != 'i' && input_string[i] != 'I' && input_string[i] != 'o' && input_string[i] != 'O' && input_string[i] != 'u' && input_string[i] != 'U') {
            consonant_string[j++] = input_string[i];
        }
    }
    consonant_string[j] = '\0';

    printf("\nOriginal string: %s", input_string);
    printf("\nInverted string: %s", inverted_string);
    printf("\nUppercase string: %s", uppercase_string);
    printf("\nConsonant string: %s", consonant_string);

    return 0;
}