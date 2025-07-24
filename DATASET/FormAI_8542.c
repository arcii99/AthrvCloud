//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char morse_code[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // Morse code table
    char input_text[100], output_morse[100];
    int i, j, k;

    printf("Enter text to convert to Morse code: ");
    fgets(input_text, 100, stdin);

    for(i = 0; i < strlen(input_text); i++) {
        if(input_text[i] == ' ') { // If there is a space, just add a space to the output
            output_morse[i] = ' ';
            continue; // Skip the rest of the loop
        }
        int index = input_text[i] - 'a'; // Get the index of the letter in the Morse code table
        for(j = 0; j < strlen(morse_code[index]); j++) {
            output_morse[k] = morse_code[index][j]; // Add the Morse code for the letter to the output
            k++;
            output_morse[k] = ' '; // Add a space between each letter's Morse code
            k++;
        }
    }

    printf("Morse code: %s", output_morse);

    return 0;
}