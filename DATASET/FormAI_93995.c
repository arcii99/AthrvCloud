//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
// Enter stage, the C compiler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Prologue
    printf("O fair programmer, whose code doth flow,\n");
    printf("I present to thee a problem to know:\n");
    printf("Spam messages in a chatroom doth grow,\n");
    printf("How can we tell friend from foe?\n\n");

    // Act 1: Reading the Message
    printf("To begin, let us read the message at hand,\n");
    printf("A careful analysis shall be our stand.\n");
    printf("Please enter the message to scan:\n");

    char message[100];
    fgets(message, 100, stdin);

    // Act 2: Spam Detection
    printf("\nNow, let us determine the message's fate,\n");
    printf("Is it spam? Or is it something great?\n");

    int count = 0, i = 0;

    while (i < strlen(message)) {
        if (message[i] == 'c' || message[i] == 'C') {
            i++;
            if (i < strlen(message) && message[i] == 'a') {
                i++;
                if (i < strlen(message) && message[i] == 's') {
                    i++;
                    if (i < strlen(message) && message[i] == 'h') {
                        i++;
                        if (i < strlen(message) && (message[i] == ' ' || message[i] == '\n')) {
                            count++;
                        }
                    }
                }
            }
        } else {
            i++;
        }
    }

    if (count >= 2) {
        printf("\nA plague upon this message, 'tis surely spam!\n");
    } else {
        printf("\nThis message hath passed our test,\n");
        printf("No spam here, let us all rest.\n");
    }

    // Epilogue
    printf("\nThus ends our little play,\n");
    printf("May your code be bug-free and never stray.\n");
    printf("Fare thee well, and have a lovely day!\n");

    return 0;
}