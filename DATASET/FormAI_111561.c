//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to translate the Alien Language
void alienTranslator(char inputString[]) {
    int i, j;
    int length = strlen(inputString);  // Get the length of the input string
 
    // Initializing the variable to hold the translated string
    char translatedString[length];
    
    // Loop through each character of the input string
    for (i = 0; i < length; i++) {
        if (inputString[i] == 'a') {
            // Convert 'a' to 'o'
            translatedString[i] = 'o';
        } else if (inputString[i] == 'b') {
            // Convert 'b' to 'e'
            translatedString[i] = 'e';
        } else if (inputString[i] == 'c') {
            // Convert 'c' to 'i'
            translatedString[i] = 'i';
        } else if (inputString[i] == 'd') {
            // Convert 'd' to 'u'
            translatedString[i] = 'u';
        } else if (inputString[i] == 'e') {
            // Convert 'e' to 'a'
            translatedString[i] = 'a';
        } else if (inputString[i] == 'f') {
            // Convert 'f' to 'd'
            translatedString[i] = 'd';
        } else if (inputString[i] == 'g') {
            // Convert 'g' to 'h'
            translatedString[i] = 'h';
        } else if (inputString[i] == 'h') {
            // Convert 'h' to 'y'
            translatedString[i] = 'y';
        } else if (inputString[i] == 'i') {
            // Convert 'i' to 'n'
            translatedString[i] = 'n';
        } else if (inputString[i] == 'j') {
            // Convert 'j' to 'm'
            translatedString[i] = 'm';
        } else if (inputString[i] == 'k') {
            // Convert 'k' to 'p'
            translatedString[i] = 'p';
        } else if (inputString[i] == 'l') {
            // Convert 'l' to 'r'
            translatedString[i] = 'r';
        } else if (inputString[i] == 'm') {
            // Convert 'm' to 't'
            translatedString[i] = 't';
        } else if (inputString[i] == 'n') {
            // Convert 'n' to 's'
            translatedString[i] = 's';
        } else if (inputString[i] == 'o') {
            // Convert 'o' to 'l'
            translatedString[i] = 'l';
        } else if (inputString[i] == 'p') {
            // Convert 'p' to 'f'
            translatedString[i] = 'f';
        } else if (inputString[i] == 'q') {
            // Convert 'q' to 'w'
            translatedString[i] = 'w';
        } else if (inputString[i] == 'r') {
            // Convert 'r' to 'z'
            translatedString[i] = 'z';
        } else if (inputString[i] == 's') {
            // Convert 's' to 'x'
            translatedString[i] = 'x';
        } else if (inputString[i] == 't') {
            // Convert 't' to 'v'
            translatedString[i] = 'v';
        } else if (inputString[i] == 'u') {
            // Convert 'u' to 'j'
            translatedString[i] = 'j';
        } else if (inputString[i] == 'v') {
            // Convert 'v' to 'g'
            translatedString[i] = 'g';
        } else if (inputString[i] == 'w') {
            // Convert 'w' to 'b'
            translatedString[i] = 'b';
        } else if (inputString[i] == 'x') {
            // Convert 'x' to 'q'
            translatedString[i] = 'q';
        } else if (inputString[i] == 'y') {
            // Convert 'y' to 'k'
            translatedString[i] = 'k';
        } else if (inputString[i] == 'z') {
            // Convert 'z' to 'c'
            translatedString[i] = 'c';
        } else {
            // If the character is not in the Alien language, just copy it to the translated string
            translatedString[i] = inputString[i];
        }
    }

    // Print the translated string
    printf("The translated string is: %s", translatedString);
}

int main() {
    char inputString[500];
    printf("Enter a string in Alien language (using only lowercase letters): ");
    scanf("%s", inputString);
    alienTranslator(inputString);  // Call the alienTranslator function
    return 0;
}