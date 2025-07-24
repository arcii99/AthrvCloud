//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void morseCode(char *text);

int main() {
    char input[100];
    printf("Enter text to convert to Morse code:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    morseCode(input);
    return 0;
}

void morseCode(char *text) {
    char morse[37][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."},
        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"},
        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"-----"},
        {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."},
        {"-...."}, {"--..."}, {"---.."}, {"----."}
    };
    char *capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    char *letter = text;
    int i, j, k;
    for(i = 0; i < strlen(letter); i++) {
        for(j = 0; j < strlen(capital); j++) {
            if(toupper(*(letter + i)) == *(capital + j)) {
                for(k = 0; k < strlen(*(morse + j)); k++) {
                    printf("%c ", *(*(morse + j) + k));
                }
                printf("    ");
            }
        }
     }
}