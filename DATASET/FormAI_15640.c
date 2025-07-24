//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void toMorse(char *string) {
    const char *MORSE_CODE[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", 
        "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    while (*string) {
        if (*string >= 'A' && *string <= 'Z') {
            printf("%s ", MORSE_CODE[*string - 'A']);
        }
        else if (*string >= 'a' && *string <= 'z') {
            printf("%s ", MORSE_CODE[*string - 'a']);
        }
        else if (*string == ' ') {
            printf("  ");
        }
        string++;
    }
}

int main() {
    char input[100];
    printf("Enter text to be converted to Morse code: ");
    fgets(input, 100, stdin);
    printf("Morse Code: ");
    toMorse(input);
    printf("\n");
    return 0;
}