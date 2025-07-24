//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Define a lookup table for Morse code
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "
};

// Define a lookup table for alphabets and numbers
const char *alpha_num[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
    "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "
};

void print_morse_code(char *s) {
    int i, j;
    printf("Morse Code Translation: ");
    // Iterate over each character in the input string
    for (i = 0; i < strlen(s); i++) {
        // Iterate over the lookup table to find the corresponding Morse code for the character
        for (j = 0; j < 37; j++) {
            if (toupper(s[i]) == *alpha_num[j]) {
                printf("%s ", *(morse_code+j));
                break;
            }
        }
    }
}

int main() {
    char string[100];
    printf("Enter a message to convert to Morse code: ");
    fgets(string, 100, stdin);
    // Pass the input string to the translation function
    print_morse_code(string);
    return 0;
}