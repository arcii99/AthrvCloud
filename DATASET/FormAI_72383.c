//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h> 

int main() 
{ 
    printf("Welcome to the C Email Client Example Program!\n\n");

    // Code for accessing email account and displaying inbox

    printf("You have 5 new emails in your inbox.\n"); 

    // Code for displaying email content and giving options to reply or delete

    printf("Would you like to reply or delete an email?\n");
    char option;
    scanf("%c", &option);
    
    switch(option) {
        case 'r':
        case 'R':
            printf("Replying to email...\n");
            // Code for composing and sending a reply email
            printf("Email sent!\n");
            break;
        case 'd':
        case 'D':
            printf("Deleting email...\n");
            // Code for deleting email from inbox
            printf("Email deleted!\n");
            break;
        default:
            printf("Invalid option selected.\n");
    }

    printf("\nThank you for using the C Email Client Example Program!\n"); 

    return 0; 
}