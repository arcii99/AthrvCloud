//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the happy firewall program!\n\n");
    printf("In this program, we will be blocking any incoming messages that contain the word 'sad'.\n\n");

    char input[100];

    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    // Checking if the message contains the word "sad"
    if (strstr(input, "sad")) {
        printf("Oh no, your message contains the word 'sad'!\n");
        printf("Sorry, we cannot allow any sad messages through our firewall.\n");
    }
    else {
        printf("Great news, your message does not contain the word 'sad'!\n");
        printf("You may now proceed and send your message.\n");
    }

    printf("\nThank you for using our happy firewall program! We hope your day is filled with joy and positivity!\n");

    return 0;
}