//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <string.h>

char morseCode[36][6] = {
    {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."},
    {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
    {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"},
    {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {".----"},
    {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."},
    {"---.."}, {"----."}, {"-----"}
};

char toMorseCode(char);

int main() {
    char text[50];
    int length;
    printf("Enter text to be converted to Morse code: ");
    fgets(text, 50, stdin);
    length = strlen(text) - 1;
    printf("Morse code output: ");
    for(int i=0; i<length; i++) {
        if(text[i] == ' ') {
            printf(" ");
        }
        else {
            printf("%s ", toMorseCode(text[i]));
        }
    }
    return 0;
}

char toMorseCode(char letter) {
    if(letter >= 'a' && letter <= 'z') {
        return morseCode[letter - 'a'];
    }
    else if(letter >= 'A' && letter <= 'Z') {
        return morseCode[letter - 'A'];
    }
    else if(letter >= '0' && letter <= '9') {
        return morseCode[letter - '0' + 26];
    }
    else {
        return "";
    }
}