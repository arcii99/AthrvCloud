//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char *inputString) {
    int i, j, len;
    char morseCode[27][6] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"/"}};
    char outputString[100];
    len = strlen(inputString);
    for (i = 0; i < len; i++) {
        if (inputString[i] == ' ') {
            strcat(outputString, "/");
        } else if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
            j = inputString[i] - 'A';
            strcat(outputString, morseCode[j]);
        } else if (inputString[i] >= 'a' && inputString[i] <= 'z') {
            j = inputString[i] - 'a';
            strcat(outputString, morseCode[j]);
        }
    }
    printf("%s", outputString);
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);
    printf("Morse Code: ");
    convertToMorseCode(inputString);
    return 0;
}