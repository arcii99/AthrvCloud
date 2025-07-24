//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

typedef struct email{
    char *sender;
    char *recipients;
    char *subject;
    char *message;

}Email;


int main()
{
    //Create an email
    Email email;
    email.sender = (char*) malloc(SIZE * sizeof(char));
    email.recipients= (char*) malloc(SIZE * sizeof(char));
    email.subject= (char*) malloc(SIZE * sizeof(char));
    email.message= (char*) malloc(SIZE * sizeof(char));

    //Get input from user
    printf("Please enter your email address: ");
    fgets(email.sender, SIZE, stdin);
    
    printf("Please enter the recipients email address: ");
    fgets(email.recipients, SIZE, stdin);

    printf("Please enter the subject of your message: ");
    fgets(email.subject, SIZE, stdin);

    printf("Please enter your message: ");
    fgets(email.message, SIZE, stdin);

    //Print email details
    printf("\n\nYour email is ready to send!\n\n From: %s\n To: %s\n Subject: %s\n Message: %s\n\n", email.sender, email.recipients, email.subject, email.message);

    //Deallocate memory
    free(email.sender);
    free(email.recipients);
    free(email.subject);
    free(email.message);

    return 0;
}