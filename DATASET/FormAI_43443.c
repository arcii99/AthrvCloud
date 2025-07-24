//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

const char *alpha_numeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

const int alpha_numeric_size = sizeof(alpha_numeric) / sizeof(char);

void encode_morse_code(char *message, char *result) {
    int message_size = strlen(message);
    int index;

    for (int i = 0; i < message_size; i++) {
        if (message[i] == ' ') {
            strcat(result, "/");
        } 
        else {
            index = toupper(message[i]) - 'A';
            if (index < 0 || index > alpha_numeric_size) {
                printf("Error: Invalid character in message.\n");
                exit(1);
            }
            strcat(result, morse_code[index]);
            strcat(result, " ");
        }
    }
}

int main() {
    char message[256];
    char result[1024] = "";
    printf("Enter the message to be encoded in Morse code: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    encode_morse_code(message, result);
    printf("Morse code: %s\n", result);

    return 0;
}