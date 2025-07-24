//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

// Function to translate an alien language string
void alienLanguageTranslator(char str[]) {

    int n = strlen(str);

    // Check if the length of the string is odd or even
    if (n % 2 == 0) {
        // If even, swap every two characters of the string
        for(int i = 0; i < n; i += 2) {
            char temp = str[i];
            str[i] = str[i+1];
            str[i+1] = temp;
        }
    } else {
        // If odd, reverse the middle character of the string
        int mid = n / 2;
        char temp = str[mid];
        str[mid] = str[mid-1];
        str[mid-1] = temp;
    }

    // Output the translated string
    printf("The translated string is: %s\n", str);
}

int main() {

    char str[100];

    // Prompt the user to enter a string in the alien language
    printf("Enter a string in the alien language: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input string
    str[strcspn(str, "\n")] = 0;

    // Call the alienLanguageTranslator function to translate the string
    alienLanguageTranslator(str);

    return 0;
}