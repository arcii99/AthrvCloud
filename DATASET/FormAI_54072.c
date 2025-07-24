//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

// Recursive function to convert a text string to Morse code
void text_to_morse(char* text, int length) {
    char morse[37][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "/"};
    // Definitions to find the morse code from the text and print it
    int char_index, i, j;
    char morse_char[5];
    if (length == 0) {
        printf("\n");
        return;
    }
    // Loops through all possible characters to check if they match any of the morse code
    for (i = 1; i <= 37; i++) {
        if (strlen(morse[i-1]) == length) {
            // If a match is found, print the morse code, then call the function again with the remaining text string
            char_index = 0;
            for (j = 0; j < length; j++) {
                if (text[j] == morse[i-1][j]) {
                    char_index++;
                }
            }
            if (char_index == length) {
                strncpy(morse_char, morse[i-1], length);
                morse_char[length] = '\0';
                printf("%s ", morse_char);
                text_to_morse(&text[length], strlen(&text[length]));
                return;
            }
        }
    }
    // If no match is found for the current text string, call the function again with the remaining text string
    text_to_morse(&text[1], length-1);
}

int main(void) {
    char text[100];
    printf("Enter text to convert to Morse code:");
    fgets(text, sizeof(text), stdin);
    // Call the recursive function to convert the text to Morse code
    text_to_morse(text, strlen(text)-1);
    return 0;
}