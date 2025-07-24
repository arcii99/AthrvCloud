//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    int spamCount = 0; // initialize spam count to 0
    printf("Welcome to the Spam Detection System!\n");

    while(1) { // run infinitely until user manually exits

        printf("\nEnter a message: ");
        fgets(input, sizeof(input), stdin); // get user input

        if(strcmp(input, "exit\n") == 0) { // allow user to exit program with "exit" command
            printf("Exiting Spam Detection System...\n");
            break;
        }

        if(strlen(input) <= 1) { // prevent empty strings from being evaluated
            printf("Invalid input.\n");
            continue;
        }

        // evaluate input for spam keywords
        if(strstr(input, "money") || strstr(input, "cash") || strstr(input, "earn")) {
            spamCount++;
            printf("SPAM DETECTED: Please do not use spam keywords in your message.\n");
            printf("Spam count: %d\n", spamCount);
        } else {
            printf("Message is not spam.\n");
        }
        
    } // end while loop

    return 0;
}