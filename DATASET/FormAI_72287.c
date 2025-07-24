//FormAI DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // max length of input messages
#define SPAM_THRESHOLD 5 // number of messages before user is flagged as spammer

int main() {
    char messages[MAX_LEN][MAX_LEN]; // array to store messages
    int num_messages = 0; // counter for number of messages
    char input[MAX_LEN]; // variable to store user input
    int spam_count = 0; // counter for number of messages from spammer

    printf("Welcome to the Spam Detection System!\n\n");

    while (1) {
        printf("Enter a message: ");
        fgets(input, MAX_LEN, stdin); // get user input

        if (strcmp(input, "exit\n") == 0) { // exit program if user enters "exit"
            printf("\nThank you for using the Spam Detection System!\n");
            break;
        }
        
        strcpy(messages[num_messages], input); // add input to messages array
        num_messages++;

        if (num_messages >= SPAM_THRESHOLD) { // check if user has sent enough messages to be flagged as spammer
            int same_message_count = 0; // counter to keep track of how many messages are the same as the last message
            for (int i = num_messages - SPAM_THRESHOLD; i < num_messages - 1; i++) { // iterate over previous messages
                if (strcmp(messages[i], messages[num_messages - 1]) == 0) { // check if message is the same as the last one
                    same_message_count++;
                }
            }
            if (same_message_count == SPAM_THRESHOLD - 1) { // if all previous messages are the same as the last one, flag user as spammer
                printf("\nUser has been flagged as a potential spammer!\n");
                spam_count++;
            }
            if (spam_count >= 3) { // if user has been flagged as spammer 3 times, block them
                printf("\nUser has been blocked due to excessive spamming!\n");
                break;
            }
        }
    }

    return 0;
}