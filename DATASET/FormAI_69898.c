//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toMorseCode(char *str) {
    int i, j;
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "};
    char *alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", ".", " "};

    // Loop through each character in the string
    for(i = 0; i < strlen(str); i++) {
        // Convert uppercase characters to lowercase
        if(isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
        // Loop through each letter in the morse code array
        for(j = 0; j < 28; j++) {
            // Compare the current character to each letter in the alphabet array
            if(strcmp(alphabet[j], &str[i]) == 0) {
                printf("%s ", morseCode[j]);
                break;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string:\n");
    fgets(str, 100, stdin);

    // Remove newline character at the end of the input string
    str[strcspn(str, "\n")] = 0;

    printf("\nMorse code translation:\n");
    toMorseCode(str);

    printf("\n");

    return 0;
}