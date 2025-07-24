//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *morse_table[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char *morse_symbols[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

// function to convert text to morse code
char *text_to_morse(char *text) {
    char *morse = malloc(sizeof(char) * strlen(text) * 5); // allocate memory for morse code string
    memset(morse, '\0', sizeof(char) * strlen(text) * 5);
    
    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) { // convert only alphabets to morse code
            int index = toupper(text[i]) - 'A';
            strcat(morse, morse_table[index]); // append morse code to morse string
            strcat(morse, " "); // add a space between each morse symbol
        }
    }
    
    return morse;
}

int main() {
    char text[100] = {'\0'};
    printf("Enter a string to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // remove trailing '\n'
    
    char *morse = text_to_morse(text);
    printf("Morse code: %s\n", morse);
    free(morse); // free memory allocated for morse string
    
    // paranoid code to overwrite text buffer with garbage data
    int len = strlen(text);
    char garbage[len];
    memset(&garbage, 'X', len);
    memcpy(text, &garbage, len);
    printf("Garbage data: %s\n", text);

    return 0;
}