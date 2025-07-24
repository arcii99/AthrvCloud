//FormAI DATASET v1.0 Category: Email Client ; Style: complex
//Importing required libraries
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Main function
int main()
{
    //Declaring variables
    char email[50], recipient[50], subject[100], message[500];

    //Getting email credentials
    printf("Enter your email address: ");
    scanf("%s", email);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter subject of email: ");
    scanf("%s", subject);
    printf("Enter message of email: ");
    scanf("%s", message);

    //Formatting email message
    char formatted_message[600];
    sprintf(formatted_message, "To: %s\nFrom: %s\nSubject: %s\n\n%s", recipient, email, subject, message);

    //Creating email file
    FILE *fp;
    fp = fopen("email.txt", "w");
    if(fp == NULL)
    {
        printf("Error creating email file!");
        exit(1);
    }

    //Writing formatted message to email file
    fprintf(fp, "%s", formatted_message);
    fclose(fp);

    //Displaying confirmation message
    printf("\nEmail saved in file email.txt!");
    return 0;
}