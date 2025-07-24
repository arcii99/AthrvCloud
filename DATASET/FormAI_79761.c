//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>

// Declare Morse code table
char morseTable[36][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

// Function to convert string to Morse code
void stringToMorse(char *s) {
    // Loop through each character in string
    for(int i = 0; i < strlen(s); i++) {
        // Check if character is upper case
        if(s[i] >= 65 && s[i] <= 90) {
            printf("%s ", morseTable[s[i] - 65]);
        }
        // Check if character is lower case
        else if(s[i] >= 97 && s[i] <= 122) {
            printf("%s ", morseTable[s[i] - 97]);
        }
        // Check if character is a number
        else if(s[i] >= 48 && s[i] <= 57) {
            printf("%s ", morseTable[s[i] - 22]);
        }
        // If character is not a letter or number, print a space
        else {
            printf(" ");
        }
    }
}

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 100, stdin);
    printf("Morse code: ");
    stringToMorse(input);
    printf("\n");
    return 0;
}