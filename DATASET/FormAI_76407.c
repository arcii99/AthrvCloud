//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert char to Morse code
char* charToMorse(char c){
    static char* morseArray[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                 "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                 "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "\0"};
    static char* alphaArray = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    int i;
    // loop through the alphaArray to find the Morse value of the character
    for(i = 0; alphaArray[i]!= '\0'; i++){
        if (alphaArray[i] == toupper(c))
            return morseArray[i];
    }
    return ""; // Return nothing if not found
}

// Function to convert text message to Morse code
char* textToMorse(char* message){
    static char morseCode[60][8]; // 60 characters max x 8 dots/dashes
    int i, j;
    for (i = 0; i < strlen(message); i++){
        char* chMorse = charToMorse(message[i]);
        for (j = 0; j < strlen(chMorse); j++){
            morseCode[i][j] = chMorse[j]; // build Morse code array
        }
    }
    morseCode[i][0] = '\0'; // make sure last element is a null terminator
    return morseCode[0];
}

int main(){
    char message[100];
    char* morse;
    printf("Enter a message in English: ");
    fgets(message, sizeof(message), stdin); // get user input
    
    morse = textToMorse(message); // call textToMorse function to convert message to Morse code
    printf("Morse code: %s", morse); // output Morse code
    
    return 0;
}