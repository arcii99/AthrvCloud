//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // maximum number of emails in the list
#define MAX_LENGTH 50 // maximum length of an email address

// function to check if an email is already in the list
int isInList(char* email, char emailList[][MAX_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(email, emailList[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char emailList[MAX_EMAILS][MAX_LENGTH];
    int emailCount = 0;

    printf("Welcome to the Mailing List Manager!\n\n");

    while (1) {
        printf("Enter an email address to add to the list (or 'q' to quit): ");
        char input[MAX_LENGTH];
        fgets(input, MAX_LENGTH, stdin); // read user input
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        if (strcmp(input, "q") == 0) { // if user wants to quit
            printf("\nHere is your mailing list:\n");
            for (int i = 0; i < emailCount; i++) {
                printf("%s\n", emailList[i]);
            }
            printf("\nThank you for using the Mailing List Manager!\n");
            break; // exit loop
        }

        if (isInList(input, emailList, emailCount)) { // if email is already in the list
            printf("\nThis email address is already in the list.\n\n");
        } else { // otherwise, add email to list
            strcpy(emailList[emailCount], input);
            emailCount++;
            printf("\nEmail address added to the list.\n\n");
        }

        if (emailCount == MAX_EMAILS) { // if list is full
            printf("Warning: Maximum number of emails reached.\n");
            break; // exit loop
        }
    }

    return 0;
}