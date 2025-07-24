//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <string.h>

int main(void) {
    char text[100];
    char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
    // Array containing the morse code for each letter of the alphabet and space character
    char* letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};
    // Array containing the letters of the alphabet and space character
    int i, j;

    printf("Enter the text to convert to morse code: ");
    fgets(text, 100, stdin); // Read user input

    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < 27; j++) {
            if (toupper(text[i]) == letters[j][0]) {
            // Check if the input character matches with any of the letters in the letters array
                printf("%s ", morse_code[j]); // If match found, print the corresponding morse code
                break;
            }
        }
        if (j == 27) {
            printf("Invalid input! Please enter letters only.\n");
            return 0; // Exit program if input contains non-letter characters
        }
    }
    printf("\n");

    return 0;
}