//FormAI DATASET v1.0 Category: Audio processing ; Style: funny
#include <stdio.h>

// The most annoying beep ever!
void beep() {
    putchar('\a');
    fflush(stdout);
} 

// The program's main function
int main() {
    printf("Welcome to our audio prank program!\n");
    printf("Type in a message and listen to it as audio\n");

    char message[100];

    printf("\nEnter your message (max 100 characters):\n");
    fgets(message, 100, stdin);

    printf("\nProcessing your message, please wait...");

    // Let's make sure the message is obnoxious and unbearable
    for(int i = 0; message[i] != '\0'; ++i) {
        if(i % 2 == 0) {
            message[i] = toupper(message[i]);
        } else {
            message[i] = tolower(message[i]);
        }
    }

    // Play some annoying sound while processing the message
    for(int i = 0; i < 10; ++i) {
        beep();
    }

    printf("\nHere's your message in audio:\n");

    // The actual prank: outputting the message in audio format using ASCII values
    for(int i = 0; message[i] != '\0'; ++i) {
        for(int j = 0; j < message[i]; ++j) {
            putchar('\a');
        }
    }

    printf("\nHope you enjoyed your audio prank! Have a terrible day!");

    return 0;
}