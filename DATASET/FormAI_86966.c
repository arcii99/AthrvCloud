//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];
    char* forbiddenCode = "sudo";
    int attempts = 0;
    int isForbidden = 0;

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter your command: \n");

    do {
        fgets(userInput, 100, stdin);

        if (strstr(userInput, forbiddenCode)) {
            printf("\nUh oh, you can't use that command!\n");
            printf("You have been flagged for possible intrusion. Please leave the system immediately!\n");
            isForbidden = 1;
        }
        else if (!strcmp(userInput, "password123\n")) {
            printf("\nHa ha ha, nice try hacker! You have failed %d times already. Give up already!\n", attempts);
            attempts++;
        }
        else {
            printf("Command executed successfully.\n");
        }
    } while (attempts < 3 && !isForbidden);

    if (isForbidden) {
        printf("\nINTRUSION DETECTED!!!\n");
        printf("Calling the FBI, CIA, and NSA. Also, making some popcorn because this is going to be fun to watch.\n");
    }
    else {
        printf("\nYou have successfully completed all commands without any intrusion attempts.\n");
        printf("Congratulations! You are a trusted user in our system.\n");
    }

    return 0;
}