//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// function to convert text to Morse code
void textToMorse(char *text, char *morse) {
    char morseCode[36][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."},
        {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."},
        {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."},
        {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}, {"-----"}, {".----"}, {"..---"},
        {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."},
        {"---.."}, {"----."}
    };
    int index;
    // convert each character of the text to Morse code
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ') {
            strcat(morse, "   "); // 3 spaces to indicate a word break
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            index = text[i] - 'A'; // find index of character in the Morse code array
            strcat(morse, morseCode[index]);
            strcat(morse, " "); // add a space after each Morse code character
        } else if(text[i] >= '0' && text[i] <= '9') {
            index = text[i] - '0' + 26; // find index of number in the Morse code array
            strcat(morse, morseCode[index]);
            strcat(morse, " ");
        } else {
            strcat(morse, ""); // if character is not alphabet or number, ignore it
        }
    }
}

int main() {
    char text[100];
    char morse[5000] = ""; // Morse code can be longer than text, so allocate enough memory
    // read input text from user
    printf("Enter text to convert to Morse code:\n");
    if(scanf("%[^\n]", text) != 1) {
        printf("Input error!\n");
        return 1;
    }
    getchar(); // consume the '\n' character left in input buffer
    // convert text to Morse code
    textToMorse(text, morse);
    // print the converted Morse code
    printf("\nMorse code for the text is:\n%s\n", morse);
    return 0;
}