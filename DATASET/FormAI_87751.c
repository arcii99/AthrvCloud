//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    char recipient[100];
    char message[500];
    char subject[100];

    printf("Enter recipient email address: ");
    scanf("%s", recipient);

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email message: ");
    scanf("%s", message);

    // code to send email goes here

    printf("Email sent successfully to %s\n", recipient);

    return 0;
}