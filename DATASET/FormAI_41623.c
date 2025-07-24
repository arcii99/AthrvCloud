//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char message[]);

int main() {
    char message[100];
    printf("Enter text to convert to Morse Code:\n");
    scanf("%[^\n]", message);
    printf("\nMorse code for the message is:\n");
    convertToMorseCode(message);
    printf("\n");
    return 0;
}

void convertToMorseCode(char message[]) {
    int i, j;
    char morseCode[26][5] = { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."} };
    // Morse code for A-Z
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ') {
            printf("   ");
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            j = (int) message[i] - 97;
            printf("%s ", morseCode[j]);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            j = (int) message[i] - 65;
            printf("%s ", morseCode[j]);
        }
    }
}