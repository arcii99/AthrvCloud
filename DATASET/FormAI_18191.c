//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define Morse code mapping
char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                 "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                 "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                 "-.--", "--..", "/", " "};

// Define function to convert string to upper case
void toUpper(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Define function to convert text to Morse code
void textToMorse(char* text) {
    int i, j;
    for (i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            printf("%s", morse[27]); // print space
        }
        else {
            for (j = 0; j < 26; j++) {
                if (text[i] == 'A' + j) {
                    printf("%s", morse[j]); // print Morse code
                    break;
                }
            }
        }
        printf(" "); // separate letters with space
    }
    printf("\n"); // end of Morse code
}

int main() {
    char text[100];
    printf("Enter text to be converted to Morse code: ");
    fgets(text, 100, stdin);

    toUpper(text); // convert input text to upper case
    textToMorse(text); // convert text to Morse code
    
    return 0;
}