//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
/*
 * Linus Torvalds style of writing, with a focus
 * on simplicity, efficiency, and elegance for the 
 * C code to Morse code conversion program.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Define the morse code representation of each letter */
const char *morse[] = {
    /* A to Z */
    ".-", "-...", "-.-.", "-..", ".", 
    "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", 
    ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", 
    "--..",

    /* 0 to 9 */ 
    "-----", ".----", "..---", "...--", "....-", 
    ".....", "-....", "--...", "---..", "----."
};

/* Convert a character to Morse code */
void toMorse(char c) {
    if (isalpha(c)) {
        /* Use uppercase letter representation */
        int index = (int)toupper(c) - 'A';
        printf("%s ", morse[index]);
    } else if(isdigit(c)) {
        /* Use digit representation */
        int index = (int)c - '0' + 26;
        printf("%s ", morse[index]);
    } else if (c == ' ') {
        /* Use a slash for space */
        printf("/ ");
    }
}

/* Convert a string to Morse code */
void strToMorse(const char *str) {
    for(int i = 0; i < strlen(str); ++i) {
        toMorse(str[i]);
    }
}

/* Test the toMorse and strToMorse functions */
int main() {
    const char *test = "C Text to Morse code Conversion Program";
    strToMorse(test);
    printf("\n");
    return 0;
}