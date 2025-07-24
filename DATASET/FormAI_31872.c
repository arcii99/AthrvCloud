//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

// Function to translate the given string to C Alien Language
void translateToCAlienLanguage(char str[]) {
    // Length of the given string
    int len = strlen(str);

    // Iterate through each character of the given string
    for (int i = 0; i < len; i++) {
        // Check if the character is a vowel
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            // Replace the vowel with the corresponding consonant in C Alien Language
            switch(str[i]) {
                case 'a': printf("b");
                          break;
                case 'e': printf("f");
                          break;
                case 'i': printf("k");
                          break;
                case 'o': printf("j");
                          break;
                case 'u': printf("p");
                          break;
            }
        }
        else {
            // If the character is a consonant, print it as it is in C Alien Language.
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main() {
    // String to be translated to C Alien Language
    char str[100];

    printf("Enter string: ");
    scanf("%[^\n]s", str);

    // Call the function to translate the given string to C Alien Language.
    printf("Translated string in C Alien Language is : ");
    translateToCAlienLanguage(str);

    return 0;
}