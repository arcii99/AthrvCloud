//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToMorse(char *input);

int main() {
    char input[100];
    printf("Enter a phrase to convert to Morse code: ");
    fgets(input, 100, stdin); // get input from user
    input[strcspn(input, "\n")] = '\0'; // remove the newline character from input
    convertToMorse(input); // call the function to convert to Morse code
    return 0;
}

void convertToMorse(char *input) {
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
                         ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", // J-S
                         "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // T-Z
                         ".----", "..---", "...--", "....-", ".....", "-....", "--...", // 1-6
                         "---..", "----.", "-----", "/", "."}; // 7-9, slash, period
    char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789./"; // Morse code equivalents

    printf("Morse code translation: ");

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) { // if the character is a letter
            printf("%s ", morseCode[toupper(input[i]) - 'A']); // look up the Morse code equivalent for the letter and print
        } else if (isdigit(input[i])) { // if the character is a digit
            printf("%s ", morseCode[input[i] - '1' + 26]); // look up the Morse code equivalent for the digit and print
        } else if (input[i] == ' ') { // if the character is a space
            printf("/ "); // print the symbol for a space in Morse code
        } else if (input[i] == '.') { // if the character is a period
            printf("%s ", morseCode[36]); // look up the Morse code equivalent for a period and print
        }
    }
}