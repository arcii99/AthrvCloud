//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

char alphabet[] = {'A', 'B', 'C', 'D', 'E',
                   'F', 'G', 'H', 'I', 'J',
                   'K', 'L', 'M', 'N', 'O',
                   'P', 'Q', 'R', 'S', 'T',
                   'U', 'V', 'W', 'X', 'Y', 'Z'};

char alienLetters[] = {'!', '@', '#', '$', '%',
                       '^', '&', '*', '(', ')',
                       '-', '_', '=', '+', '[',
                       ']', '{', '}', ';', ':',
                       ',', '.', '<', '>', '?', '/'};

void translate(char message[]) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 26; j++) {
            if (message[i] == alphabet[j]) {
                printf("%c", alienLetters[j]);
                break;
            } else if (message[i] == (alphabet[j] + 32)) {
                printf("%c", alienLetters[j]);
                break;
            } else if (message[i] == ' ') {
                printf(" ");
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    printf("Please enter a message to translate into Alien language:\n");
    fgets(message, 100, stdin);
    printf("Here is your message translated into Alien language:\n");
    translate(message);
    return 0;
}