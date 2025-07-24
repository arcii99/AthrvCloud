//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
    const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                                "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                                "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....",
                                "-....", "--...", "---..", "----."};
    const char *alpha = "abcdefghijklmnopqrstuvwxyz0123456789";
    char text[100], morse[100];
    int i, j, pos;

    printf("Enter a string in English: ");
    fgets(text, 100, stdin);

    // Convert to lower case
    for (i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Convert text to morse code
    for (i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            morse[i] = '/';
        } else {
            pos = strchr(alpha, text[i]) - alpha;
            strcpy(morse + i, morse_code[pos]);
        }
    }

    printf("Morse code for the input string is:\n");
    for (i = 0; morse[i]; i++) {
        if (morse[i] == '/') {
            printf("/ ");
        } else {
            printf("%c ", morse[i]);
        }
    }
    printf("\n");

    return 0;
}