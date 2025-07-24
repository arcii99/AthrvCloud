//FormAI DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    char toAddress[MAX_SIZE];
    char subject[MAX_SIZE];
    char body[MAX_SIZE];
    char ccAddress[MAX_SIZE];
    char bccAddress[MAX_SIZE];

    printf("Enter the email address of the recipient: ");
    fgets(toAddress, MAX_SIZE, stdin);

    printf("Enter the subject of the email: ");
    fgets(subject, MAX_SIZE, stdin);

    printf("Enter the body of the email: ");
    fgets(body, MAX_SIZE, stdin);

    printf("Do you want to cc anyone? (y/n): ");
    char ccChoice[MAX_SIZE];
    fgets(ccChoice, MAX_SIZE, stdin);
    if(ccChoice[0] == 'y') {
        printf("Enter the email address(es) to cc: ");
        fgets(ccAddress, MAX_SIZE, stdin);
    }

    printf("Do you want to bcc anyone? (y/n): ");
    char bccChoice[MAX_SIZE];
    fgets(bccChoice, MAX_SIZE, stdin);
    if(bccChoice[0] == 'y') {
        printf("Enter the email address(es) to bcc: ");
        fgets(bccAddress, MAX_SIZE, stdin);
    }

    printf("\n\nTO: %s", toAddress);
    printf("SUBJECT: %s", subject);
    printf("BODY: %s", body);
    if(ccChoice[0] == 'y'){
        printf("CC: %s", ccAddress);
    }
    if(bccChoice[0] == 'y'){
        printf("BCC: %s", bccAddress);
    }

    return 0;
}