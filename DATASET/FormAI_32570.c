//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

// Morse code array with corresponding characters
const char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", };

// Function to convert a character to Morse code
void toMorse(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        printf("%s", morseCode[ch-'A']);
    }
    else if (ch >= 'a' && ch <= 'z') {
        printf("%s", morseCode[ch-'a']);
    }
    else if (ch >= '0' && ch <= '9') {
        printf("%s", morseCode[ch-'0'+25]);
    }
    else {
        printf(" ");
    }
}

// Function to convert a string to Morse code
void convertToMorse(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        toMorse(str[i]);
        if (str[i] != ' ') {
            printf(" ");
        }
    }
}

int main() {
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);
    printf("Morse code: ");
    convertToMorse(str);
    printf("\n");
    return 0;
}