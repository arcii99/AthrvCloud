//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <string.h>

void convertToMorse(char*);
char* getCode(char*);

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    convertToMorse(text);
    return 0;
}

char* getCode(char* letter) {
    char* codes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",     // A to I
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J to R
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S to Z
    };
    char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = strchr(letters, *letter) - letters;
    return codes[index];
}

void convertToMorse(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            printf("   ");
        } else {
            printf("%s ", getCode(&text[i]));
        }
    }
}