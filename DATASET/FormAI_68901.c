//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_OUTPUT 500

// Morse code table
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/"};

// English alphabets table
char *english[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                   "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "/"};

// Helper function to get Morse code for a given character
char *get_morse_code(char c) {
    if (c >= 'a' && c <= 'z') {  // convert to uppercase if it's a lowercase alphabet
        c -= 32;
    }
    for (int i = 0; i < 27; i++) {
        if (english[i][0] == c) {
            return morse[i];
        }
    }
    return "";
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT] = "";
    printf("Enter text to convert to Morse code:\n");
    fgets(input, MAX_INPUT, stdin);
    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        char *code = get_morse_code(input[i]);
        strcat(output, code);
        strcat(output, " ");
        i++;
    }
    printf("The Morse code for \"%s\" is:\n%s\n", input, output);
    return 0;
}