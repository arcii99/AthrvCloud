//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

const char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                            "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                            "-.--", "--..", "/", "-.-.--", ".-.-.-", "--..--"};

const char* alphabet = "abcdefghijklmnopqrstuvwxyz/.,!";

int main() {
    char message[101];
    printf("Enter a string (max 100 characters): ");
    fgets(message, 100, stdin);

    int length = strlen(message);
    message[length - 1] = '\0';
    length--;

    printf("Morse Code: ");

    for (int i = 0; i < length; i++) {
        char character = tolower(message[i]);
        const char* morse = NULL;

        for (int j = 0; j < strlen(alphabet); j++) {
            if (character == alphabet[j]) {
                morse = morse_code[j];
                break;
            }
        }

        if (morse != NULL) {
            printf("%s ", morse);
        }
    }

    printf("\n");

    return 0;
}