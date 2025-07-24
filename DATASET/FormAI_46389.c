//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to translate the given string into the Alien language
void alienTranslator(char str[]) {
    
    // Length of the input string
    int len = strlen(str);
    
    // Loop through the string to replace each character
    for(int i=0; i<len; i++) {
        
        // If character is a vowel, replace it with "x"
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = 'x';
        }
        
        // If character is a consonant, replace it with the next consonant in the alphabet
        else if(str[i] >= 'b' && str[i] <= 'd' || str[i] >= 'f' && str[i] <= 'h' || str[i] >= 'j' && str[i] <= 'n' || str[i] >= 'p' && str[i] <= 't' || str[i] >= 'v' && str[i] <= 'z') {
            str[i]++;
        }
    }
    
    // Print the translated string
    printf("Alien language: %s\n", str);
}

int main() {
    // Input string
    char str[100];
    printf("Enter a string in English: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;

    // Call the alien translator function
    alienTranslator(str);
    
    return 0;
}