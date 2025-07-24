//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

// Function to convert text to morse code
void textToMorse(char* text){

    // Create an array of Morse code characters
    const char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                               "....", "..", ".---", "-.-", ".-..", "--", "-.",
                               "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                               "...-", ".--", "-..-", "-.--", "--..", " "};
    
    // Create an array of alpha-numeric characters
    const char* alphaNumeric[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                                  "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                                  "S", "T", "U", "V", "W", "X", "Y", "Z", "0",
                                  "1", "2", "3", "4", "5", "6", "7", "8", "9", " "};

    // Loop through each character in the text
    for(int i = 0; i < strlen(text); i++){
        // Determine the index of the character in the alphaNumeric array
        int index = -1;
        for(int j = 0; j < 37; j++){
            if(text[i] == alphaNumeric[j][0]){
                index = j;
                break;
            }
        }
        // If the character was not found in the alphaNumeric array, skip it
        if(index == -1){
            continue;
        }
        // Print out the corresponding Morse code character for the alphaNumeric character
        printf("%s ", morseCode[index]);
    }
    printf("\n");
}

int main() {
    // Prompt the user for input
    char text[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(text, 100, stdin);
    // Convert the text to Morse code and print out the result
    textToMorse(text);
    return 0;
}