//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {

    char text[100];
    printf("Enter the text to convert to Morse code: ");
    fgets(text, 100, stdin);

    char morse[100][5] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."},
        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"},
        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"/"}
    };
    char alpha[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char morseText[2000];

    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < strlen(alpha); j++) {
            if (text[i] == alpha[j]) {
                strcat(morseText, morse[j]);
                strcat(morseText, " ");
                break;
            }
        }
    }

    printf("\nMorse code:\n%s", morseText);

    return 0;
}