//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char input[]) {

    char morseCode[26][7] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}
    };

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            printf("%s ", morseCode[input[i] - 'A']);
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            printf("%s ", morseCode[input[i] - 'a']);
        } else if (input[i] == ' ') {
            printf("/ ");
        } else {
            printf("%c ", input[i]);
        }
    }
}

int main() {
    char input[100];

    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);

    printf("Morse code: ");
    convertToMorseCode(input);

    return 0;
}