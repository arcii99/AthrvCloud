//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>

int main() {
    // Let's create a program to transform all vowels to uppercase and all consonants to lowercase
    char text[] = "Welcome to the world of programming!";
    
    for (int i = 0; i < strlen(text); i++) {
        // First, let's check if the current character is a vowel
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
            // If it is, let's convert it to uppercase
            text[i] = toupper(text[i]);
        } else {
            // Otherwise, let's convert it to lowercase
            text[i] = tolower(text[i]);
        }
    }
    
    // Finally, let's print out the transformed text
    printf("Transformed text: %s", text);

    return 0;
}