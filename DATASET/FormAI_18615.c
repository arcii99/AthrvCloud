//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char email[1000];
    char recipient[100];
    char subject[100];
    char body[500];

    printf("Welcome to our Unique C Email Client!\n");

    printf("Enter the recipient's email address:\n");
    scanf("%s", recipient);

    printf("Enter the subject of the email:\n");
    scanf("%s", subject);

    printf("Enter the body of the email:\n");
    scanf("%s", body);

    sprintf(email, "To: %s\nSubject: %s\n\n%s", recipient, subject, body);
    printf("Email created successfully!\n\n");

    printf("Do you want to send the email (Y/N):\n");
    char choice = getchar();

    if (choice == 'Y' || choice == 'y') {
        printf("Email sent successfully to %s!\n", recipient);
    } else {
        printf("Email discarded. Goodbye!\n");
    }

    return 0;
}