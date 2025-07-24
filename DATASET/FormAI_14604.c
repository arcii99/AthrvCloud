//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    char morse[1000] = "";
    int i, j;
    const char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

    printf("Welcome to Morse Code Converter!\n");
    printf("Please enter your message: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0'; // Removes the trailing newline character

    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            strcat(morse, " / ");
        } else if (message[i] < 'A' || (message[i] > 'Z' && message[i] < 'a') || message[i] > 'z') {
            printf("Error: Input string contains invalid characters!\n");
            return 1;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            strcat(morse, morseCode[message[i] - 'A']);
            strcat(morse, " ");
        } else {
            strcat(morse, morseCode[message[i] - 'a']);
            strcat(morse, " ");
        }
    }

    printf("\nYour original message is: %s\n", message);
    printf("Your paranoid morse code message is: %s\n", morse);

    return 0;
}