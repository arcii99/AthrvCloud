//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50
#define MAX_MORSE_LENGTH 100

const char* morse_table[] = {
   ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
   ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
   "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
   "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

int main() {
    char input[MAX_INPUT_LENGTH];
    char morse_code[MAX_MORSE_LENGTH] = "";
    int i, j;

    printf("Enter a string to convert to Morse code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            strcat(morse_code, morse_table[tolower(input[i]) - 'a']);
        } else if (isdigit(input[i])) {
            strcat(morse_code, morse_table[input[i] - '0' + 25]);
        } else if (isspace(input[i])) {
            strcat(morse_code, "/");
        }
        strcat(morse_code, " ");
    }

    printf("Morse code: %s\n", morse_code);
    return 0;
}