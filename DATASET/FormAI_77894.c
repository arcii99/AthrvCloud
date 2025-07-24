//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    printf("\n\t\tWelcome to SHOCKING Text to Morse Code Converter!\n");
    printf("\n\t\tEnter the text you want to convert: ");
    
    // Define the morse code table 
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *morse_code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    char text[500], morse[500];
    int i, j, k;
    fgets(text, 500, stdin);
    
    for (i = 0, k = 0; i < strlen(text); i++) {
        // Convert uppercase to lowercase
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + ('a' - 'A');
        }
        // Search for the corresponding letter in the morse code table
        for (j = 0; j < 26; j++) {
            if (text[i] == letters[j]) {
                // Print the corresponding morse code symbol
                printf("%s", morse_code[j]);
                // Add the corresponding morse code symbol to the final string
                strcat(morse, morse_code[j]);
                // Add a space between each morse code symbol
                strcat(morse, " ");
                k += strlen(morse_code[j]) + 1;
            }
        }
        // Print "/ " for spaces in the input text and add it to the final string
        if (text[i] == ' ') {
            printf("/ ");
            strcat(morse, "/ ");
            k += 2;
        }
        // Handle non-alphabetic characters in the input text
        if (text[i] < 'A' || (text[i] > 'Z' && text[i] < 'a') || text[i] > 'z') {
            printf("%c ", text[i]);
            morse[k] = text[i];
            morse[k+1] = ' ';
            k += 2;
        }
    }
    printf("\n\n\t\tMorse Code: %s\n\n", morse);
    return 0;
}