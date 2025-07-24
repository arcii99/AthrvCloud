//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void textToMorseCode(char message[], char morseCode[]) {
    int i, j;
    char codes[37][6] = {// Morse codes for letters(A-Z) and numbers(0-9)
                          {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."},
                          {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."},
                          {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
                          {"-.--"}, {"--.."}, {"-----"}, {".----"}, {"..---"}, {"...--"}, {"....-"},
                          {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}
                        };
    char letters[MAX_SIZE][2] = { // letters(A-Z) and numbers(0-9)
                                    {"A"}, {"B"}, {"C"}, {"D"}, {"E"}, {"F"}, {"G"}, {"H"},
                                    {"I"}, {"J"}, {"K"}, {"L"}, {"M"}, {"N"}, {"O"}, {"P"},
                                    {"Q"}, {"R"}, {"S"}, {"T"}, {"U"}, {"V"}, {"W"}, {"X"},
                                    {"Y"}, {"Z"}, {"0"}, {"1"}, {"2"}, {"3"}, {"4"}, {"5"},
                                    {"6"}, {"7"}, {"8"}, {"9"}
                                };

    strcpy(morseCode, "");//Clear Morse code variable

    for(i = 0; message[i] != '\0'; i++) {
        for(j = 0; j < 36; j++) {
            if(message[i] == letters[j][0]) {//Match letter or number to Morse code
                strcat(morseCode, codes[j]);//Add Morse code for letter or number to message
                strcat(morseCode, " ");//Add space to separate codes
                break;
            }
        }
    }
}

int main() {
    char message[MAX_SIZE];
    char morseCode[MAX_SIZE*5];// Maximum size of Morse code message

    printf("Greetings! Welcome to the Text to Morse Code Conversion Program\n");

    while(1) {
        printf("\nEnter a message to convert to Morse code (max %d characters): ", MAX_SIZE);
        fgets(message, MAX_SIZE, stdin);//Read input from user

        if(message[0] != '\n') {
            textToMorseCode(message, morseCode);
            printf("Morse Code: %s", morseCode);
        }
        else {
            printf("Goodbye! Thanks for using our Text to Morse Code Conversion Program\n");
            break;
        }
    }
    return 0;
}