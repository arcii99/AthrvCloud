//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code lookup table
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                   ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/", NULL};

// Function to convert a single character to Morse code
void convertToMorse(char ch) {
    int i;
    // Search the Morse code table for the character
    for (i = 0; morse[i] != NULL; i++) {
        if (morse[i][0] == ch) {
            printf("%s ", morse[i]+1);   // Print the Morse code and skip the first character
            return;
        }
    }
    printf(" ");   // If the character is not found, print a space
}

// Function to convert a string to Morse code
void convertString(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        convertToMorse(toupper(str[i]));   // Convert each character to uppercase before converting to Morse code
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Morse code: ");
    convertString(str);
    return 0;
}