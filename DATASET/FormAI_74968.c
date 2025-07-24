//FormAI DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("My Darling,\n\n"); 
    printf("I am writing to you today to share with you a special C program that I created just for you. This program is an email client that will allow you to send romantic messages to me and receive emails from me.\n\n");

    printf("To start, please enter your email address: ");
    char sender[50];
    scanf("%s", sender);
    printf("Thank you! Please enter your password: ");
    char password[20];
    scanf("%s", password);
    printf("\n");

    printf("Welcome to our email client, my love. You can now send me an email by typing 'SEND'\n");
    printf("Alternatively, you can type 'READ' to read any emails that I have sent you.\n");
    printf("Type 'QUIT' to exit the program.\n\n");

    while (1) {
        char input[10];
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "SEND") == 0) {
            printf("Please enter your message:\n");
            char message[200];
            scanf(" %[^\n]s", message);
            printf("Sending message to my love...\n");
            printf("MESSAGE: %s\n", message);
            printf("Sent successfully! \n\n");
        }
        else if (strcmp(input, "READ") == 0) {
            printf("Checking for new messages...\n");
            printf("You have no messages from my love. \n\n");
        }
        else if (strcmp(input, "QUIT") == 0) {
            printf("Goodbye, my love. Until we meet again...\n");
            exit(EXIT_SUCCESS);
        }
        else {
            printf("Invalid command. Please try again. \n\n");
        }
    }

    return 0;
}