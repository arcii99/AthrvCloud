//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

const char *MORSE_CODE[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

const char *CHARACTERS[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", 
                            "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", 
                            "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                            ".", ",", "?", "!", "'", "\"", "(", ")", "&", ":", ";", "/", "+", "-", "=", "@", " " };

int main() {
    char input[100], morse[500]; // input string and morse code string
    int length, i, j, index; // loop variables and index
    
    printf("Enter a string: "); // ask user for input
    fgets(input, sizeof(input), stdin); // get input from user
    length = strlen(input) - 1; // calculate length of input string
    
    // convert input string to morse code
    for (i = 0; i < length; i++) {
        index = -1; // reset index
        // find index of character in CHARACTERS array
        for (j = 0; j < sizeof(CHARACTERS)/sizeof(CHARACTERS[0]); j++) {
            if (toupper(input[i]) == CHARACTERS[j][0]) {
                index = j;
                break;
            }
        }
        // append morse code to morse string
        if (index == -1) {
            strcat(morse, "/"); // insert slash for unknown character
        } else {
            strcat(morse, MORSE_CODE[index]); // append morse code for character
        }
        strcat(morse, " "); // insert space between characters
    }
    
    printf("Morse Code: %s", morse); // print morse code
    
    return 0;
}