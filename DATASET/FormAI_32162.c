//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100	//Maximum input length
#define MAX_MORSE 50	//Maximum Morse code length

char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "--..--", ".-.-.-", "..--..", "/"}; //List of Morse codes for each letter

char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ",", ".", "?", " "}; //List of letters and symbols

void text_to_morse(char *input, char *output) {
    char *token;
    char temp[MAX_INPUT];
    strcpy(temp, input);
    token = strtok(temp, " "); //Split input into tokens
    while (token != NULL) {
        int i;
        for (i = 0; i < sizeof(letters) / sizeof(letters[0]); i++) {
            if (strcmp(token, letters[i]) == 0) { //Compare token with each letter/symbol
                strcat(output, morse_codes[i]); //If match found, append Morse code to output string
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_INPUT], output[MAX_MORSE];
    printf("Enter a sentence to convert to Morse code: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; //Remove newline character from input
    output[0] = '\0'; //Initialize output string
    text_to_morse(input, output);
    printf("Morse code: %s\n", output);
    return 0;
}