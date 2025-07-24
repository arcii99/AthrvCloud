//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <string.h>

void convertToMorse(char[], char[]);
void printMorseCode(char[]);

int main() {
    char message[100], morseCode[500];

    printf("Hello, my love! This program will convert your love message to Morse code.\n");
    printf("Please type in your message (max 100 characters): ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("\nConverting your message to Morse code...\n\n");
    convertToMorse(message, morseCode);

    printf("Your love message in Morse code is:\n\n");
    printMorseCode(morseCode);
    printf("\nOh, what sweet music to my ears! I love you more than words can express.\n");

    return 0;
}

void convertToMorse(char message[], char morseCode[]) {
    char alphabet[27][4] = { // Morse code for all letters
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."},
        {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."},
        {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}, {""}
    };

    for (int i = 0; message[i] != '\0'; i++) {
        char letter = message[i];
        if (letter >= 65 && letter <= 90) { // Uppercase letters
            strcat(morseCode, alphabet[letter-65]);
        } else if (letter >= 97 && letter <= 122) { // Lowercase letters
            strcat(morseCode, alphabet[letter-97]);
        } else if (letter >= 48 && letter <= 57) { // Numbers
            char number[3] = "";
            sprintf(number, "%s", alphabet[letter-22]);
            strcat(morseCode, number);
        } else if (letter == 32) { // Space
            strcat(morseCode, "/");
        }
        strcat(morseCode, " "); // Space between each letter/number
    }
}

void printMorseCode(char morseCode[]) {
    for (int i = 0; morseCode[i] != '\0'; i++) {
        if (morseCode[i] == '.') {
            printf("•");
        } else if (morseCode[i] == '-') {
            printf("─");
        } else if (morseCode[i] == '/') {
            printf(" ");
        } else if (morseCode[i] == ' ') {
            printf(" ");
            continue;
        }

        if (morseCode[i+1] == ' ' || morseCode[i+1] == '\0') {
            printf("   "); // Space between each letter/number
        } else {
            printf(" ");
        }
    }
}