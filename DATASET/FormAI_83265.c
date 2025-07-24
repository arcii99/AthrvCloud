//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

const char *morse_alphabets[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

void text_to_morse_code(char text[]) {
    int length = strlen(text);

    for(int i=0; i<length; i++) {
        char ch = text[i];

        if(ch == ' ') {
            printf("    "); // 4 spaces for word space
            continue;
        } else if(ch >= 'a' && ch <= 'z') {
            ch -= 32; // Convert lowercase to uppercase
        }

        if(ch >= 'A' && ch <= 'Z') {
            printf("%s ", morse_alphabets[ch-'A']);
        } else if(ch >= '0' && ch <= '9') {
            printf("%s ", morse_alphabets[ch-'0'+25]);
        }
    }
}

int main() {
    char text[100];

    printf("Enter text: ");
    gets(text);

    text_to_morse_code(text);

    return 0;
}