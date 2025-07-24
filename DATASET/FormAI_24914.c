//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <string.h>

void morseCode(char text[]) {
    // Morse code characters
    const char *alphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                              "....", "..", ".---", "-.-", ".-..", "--", "-.",
                              "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                              "...-", ".--", "-..-", "-.--", "--.."};
    const char *numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....",
                             "-....", "--...", "---..", "----."};
    const char *special[] = {".-.-.-", "--..--", "..--..", "-.-.--"};

    // Iterate over each character of the string
    for (int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]); // Convert to lowercase

        if (isalnum(c)) { // Alphanumeric characters
            if (isdigit(c)) { // Numbers
                printf("%s ", numbers[c - '0']);
            } else { // Letters
                printf("%s ", alphabet[c - 'a']);
            }
        } else { // Special characters
            switch (c) {
                case ' ':
                    printf("/ ");
                    break;
                case '.':
                case ',':
                case '?':
                    printf("%s ", special[c - '.']);
                    break;
                default:
                    printf("%c ", c);
            }
        }
    }
}

int main() {
    char text[] = "Hello, World!";

    morseCode(text);

    return 0;
}