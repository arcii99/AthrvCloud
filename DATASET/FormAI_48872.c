//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Morse code array
const char *morse_code[] = { ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",   "....", "..",   ".---", "-.-",  ".-..", "--", "-.",   "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--.." };

// Define character array
const char *characters[] = { "A",   "B",   "C",   "D",   "E",   "F",   "G",   "H",  "I",   "J",   "K",   "L",   "M",  "N",   "O",   "P",   "Q",   "R",   "S",   "T",  "U",    "V",   "W",    "X",   "Y",   "Z" };

// Function to convert text to Morse code
void text_to_morse(char input_text[]) {
    int i, j;
    for (i = 0; input_text[i] != '\0'; i++) {
        if (input_text[i] == ' ') {
            printf("   ");
        }
        else {
            for (j = 0; j < 26; j++) {
                if (toupper(input_text[i]) == *characters[j]) {
                    printf("%s", morse_code[j]);
                    printf(" ");
                }
            }
        }
    }
    printf("\n");
}

int main() {
    char input_text[200];
    printf("Enter the text to convert to Morse code:\n");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = '\0'; // Remove newline character from input
    printf("Morse code: ");
    text_to_morse(input_text);
    return 0;
}