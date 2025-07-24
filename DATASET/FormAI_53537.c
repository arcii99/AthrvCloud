//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};
char* alpha = "abcdefghijklmnopqrstuvwxyz";
char* convertToMorse(char* str) {
    char* morse_str = malloc(strlen(str) * 5 + 1);
    int i, j;
    for(i = 0; i < strlen(str); i++) {
        if(isalpha(str[i])) {
            for(j = 0; j < 26; j++) {
                if(tolower(str[i]) == alpha[j]) {
                    strcat(morse_str, morse[j]);
                    strcat(morse_str, " ");
                    break;
                }
            }
        } else if(str[i] == ' ') {
            strcat(morse_str, "/ ");
        }
    }
    morse_str[strlen(morse_str) - 1] = '\0'; // remove trailing space
    return morse_str;
}

int main() {
    char input[256], choice;
    do {
        printf("Enter text to convert to Morse code: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character
        printf("Morse code: %s\n", convertToMorse(input));
        printf("Do you want to convert another text? (Y/N) ");
        scanf(" %c", &choice);
        getchar(); // remove newline character from buffer
    } while(tolower(choice) == 'y');
    return 0;
}