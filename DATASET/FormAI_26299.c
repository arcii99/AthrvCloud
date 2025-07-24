//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to translate given string into Alien Language
void translateToAlienLanguage(char* str) {
    int len = strlen(str);
    
    // Loop through the string and replace consonants with 'o' and vowels with 'i'
    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
                str[i] = 'o';
            }
            else {
                str[i] = 'i';
            }
        }
    }
    
    // Print the translated string
    printf("Translated Alien Language: %s\n", str);
}

int main() {
    char input_str[1000];
    
    // Take user input
    printf("Enter the string you want to translate into Alien Language: ");
    fgets(input_str, 1000, stdin);
    
    // Remove newline character from the input string
    input_str[strcspn(input_str, "\n")] = 0;
    
    // Call function to translate the input string into Alien Language
    translateToAlienLanguage(input_str);
    
    return 0;
}