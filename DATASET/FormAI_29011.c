//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for Morse Code mapping
struct MorseCode {
    char letter;
    char code[10];
};

//Function to convert text to Morse code
void convertToMorse(char *text, struct MorseCode *morseMap, int size) {
    int i, j, k=0;
    for(i=0; i<strlen(text); i++) {
        for(j=0; j<size; j++) {
            if(text[i] == morseMap[j].letter) {
                printf("%s ", morseMap[j].code);
                k++;
            }
        }
        if(text[i] == ' ') {
            printf("   ");
            k++;
        }
    }
    if(k == 0) {
        printf("No valid input found!");
    }
}

int main() {
    //Initialize Morse Code mapping
    struct MorseCode morseMap[] = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'0', "-----"},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},
        {' ', " "}
    };

    //Get Input Text
    char text[100];
    printf("Enter the text to convert to Morse Code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    //Convert to Morse Code
    printf("Morse Code: ");
    convertToMorse(text, morseMap, sizeof(morseMap)/sizeof(morseMap[0]));

    return 0;
}