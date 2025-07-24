//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Morse code lookup table
const char* morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                        "-.--", "--.." };

// Function to convert a character to Morse code
void charToMorse(char c) {
    if (c >= 'a' && c <= 'z') {   // handle lowercase letters
        printf("%s ", morse[c-'a']);
    } else if (c >= 'A' && c <= 'Z') {   // handle uppercase letters
        printf("%s ", morse[c-'A']);
    } else if (c >= '0' && c <= '9') {   // handle numbers
        printf("%s ", morse[c-'0'+26]);
    } else {                           // handle unknown characters by printing a question mark
        printf("? ");
    }
}

int main() {
    char msg[100];  // array to store user input message
    printf("Enter a message to convert to Morse code: ");
    gets(msg);      // read user input

    // iterate over each character in the message and convert to Morse code
    for (int i = 0; i < strlen(msg); i++) {
        charToMorse(msg[i]);
    }

    return 0;   // end of program
}