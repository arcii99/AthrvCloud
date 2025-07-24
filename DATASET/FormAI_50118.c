//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>

// function to convert text to morse code
void text_to_morse(char* text) {
    int i, j;
    char morse_code[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // array of morse code for each letter of the alphabet
    
    // loop through each character in the text string
    for (i = 0; i < strlen(text); i++) {
        // check if character is a space
        if (text[i] == ' ') {
            printf("  ");
        }
        else {
            // find index of letter in the alphabet
            j = text[i] - 'A';
            // convert letter to morse code
            printf("%s ", morse_code[j]);
        }
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    printf("Morse code: ");
    text_to_morse(text);
    return 0;
}