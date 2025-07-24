//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <string.h>

// Morse Code lookup table
char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

// ASCII character lookup table
char *asciiCode[36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void convertToMorseCode(char str[]) {
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        char c = toupper(str[i]);

        // Check if character is in lookup table
        if(c >= 'A' && c <= 'Z') {
            printf("%s ", morseCode[c - 'A']);
        }
        else if(c >= '0' && c <= '9') {
            printf("%s ", morseCode[c - '0' + 26]);
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Morse Code: ");
    convertToMorseCode(str);

    return 0;
}