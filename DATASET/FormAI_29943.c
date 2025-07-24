//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    char *alienLanguage = "x0qKdczsk!$*$ioqFgxtmz56WZk"; // Alien language mapping
    char input[1000]; // Max input length set to 1000 characters
 
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter your message in alien language: ");
    scanf("%[^\n]%*c", input); // Take in the entire input string and discard the newline character
 
    printf("\nYour original message was: %s\n", input); // Print the input string back to the user
    
    char translatedString[1000]; // Creating a buffer to hold the translated string
    int i;
 
    for (i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        int asciiCode = (int)currentChar; // Get the ASCII code for the current character
 
        if (asciiCode >= 65 && asciiCode <= 90) {
            asciiCode += 32; // Convert uppercase to lowercase ASCII code
        }
 
        if (asciiCode >= 97 && asciiCode <= 122) {
            char translatedChar = alienLanguage[asciiCode - 97]; // Translate lowercase character
            strncat(translatedString, &translatedChar, 1); // Add the translated character to the output string
        } else {
            strncat(translatedString, &currentChar, 1); // Append non-letter characters to the output string as-is
        }
    }
 
    printf("\nYour translated message is: %s\n", translatedString); // Print the final translated string
 
    return 0;
}