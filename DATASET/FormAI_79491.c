//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the phrase you want to translate:\n");
    fgets(input, 100, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    int i, j;
    for (i = 0; input[i] != '\0'; i++) {
        // Check if character is lowercase letter
        if (input[i] >= 'a' && input[i] <= 'z') {
            // Translate to C Alien Language
            if (i % 2 == 0) {
                input[i] = ((input[i] - 'a') * 2) + 'a';
            } else {
                input[i] = ((input[i] - 'a') * 2) + 'b';
            }
        }
    }
    
    printf("Your translated phrase is: %s\n", input);
    printf("Thank you for using the Alien Language Translator!\n");
    
    return 0;
}