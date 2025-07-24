//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <string.h>

//Function to convert text to Morse code using look-up table
void textToMorse(char text[]) {
    //Morse code look-up table
    char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    //Iterate through each character in the text string
    for (int i = 0; i < strlen(text); i++) {
        //Convert upper case letter to its corresponding Morse code sequence
        if (text[i] >= 'A' && text[i] <= 'Z') {
            printf("%s ", morseCode[text[i] - 'A']);
        }
        //Convert lower case letter to its corresponding Morse code sequence
        else if (text[i] >= 'a' && text[i] <= 'z') {
            printf("%s ", morseCode[text[i] - 'a']);
        }
        //Print space for a space character
        else if (text[i] == ' ') {
            printf(" ");
        }
    }
}

int main() {
    char text[100];

    //Get input text from user
    printf("Enter text: ");
    fgets(text, 100, stdin);

    //Convert text to Morse code
    textToMorse(text);

    return 0;
}