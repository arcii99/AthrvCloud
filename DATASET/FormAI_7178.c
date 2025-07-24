//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char *text) {
    char morse[26][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // Morse code for each letter of the alphabet
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') { // Check for spaces
            printf("   ");
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') { // Convert uppercase letters
            printf("%s ", morse[text[i] - 'A']);
        }
        else if (text[i] >= 'a' && text[i] <= 'z') { // Convert lowercase letters
            printf("%s ", morse[text[i] - 'a']);
        }
    }
}

int main() {
    char text[100];
    printf("Enter a text to convert to Morse code: ");
    fgets(text, 100, stdin);

    printf("Morse code: ");
    textToMorse(text); // Call function to convert text to Morse code

    return 0;
}