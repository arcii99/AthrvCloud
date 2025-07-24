//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter the string you want to manipulate: ");
    fgets(input, 100, stdin);

    // Removing all the vowels from the input string
    int len = strlen(input);
    char output[100];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    printf("Manipulated string without vowels: %s\n", output);

    // Reversing the string
    len = strlen(output);
    for (int i = 0; i < len/2; i++) {
        char temp = output[i];
        output[i] = output[len-1-i];
        output[len-1-i] = temp;
    }

    printf("Reversed manipulated string without vowels: %s\n", output);

    // Replacing all spaces with hyphens
    len = strlen(output);
    for (int i = 0; i < len; i++) {
        if (output[i] == ' ') {
            output[i] = '-';
        }
    }

    printf("Final manipulated string: %s\n", output);

    return 0;
}