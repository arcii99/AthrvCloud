//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

void translate(char message[]) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == '1') {
            message[i] = 'A';
        }
        else if (message[i] == '2') {
            message[i] = 'B';
        }
        else if (message[i] == '3') {
            message[i] = 'C';
        }
        else if (message[i] == '4') {
            message[i] = 'D';
        }
        else if (message[i] == '5') {
            message[i] = 'E';
        }
        else if (message[i] == '6') {
            message[i] = 'F';
        }
        else if (message[i] == '7') {
            message[i] = 'G';
        }
        else if (message[i] == '8') {
            message[i] = 'H';
        }
        else if (message[i] == '9') {
            message[i] = 'I';
        }
        else if (message[i] == '0') {
            message[i] = 'J';
        }
        else if (message[i] == 'X') {
            message[i] = 'Z';
        }
    }
}

int main() {
    char message[1000];
    printf("Enter alien language message: ");
    fgets(message, sizeof(message), stdin);
    printf("Translating message...\n");
    translate(message);
    printf("Translated message: %s", message);
    return 0;
}