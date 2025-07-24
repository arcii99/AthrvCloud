//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the C Email Client! Let's send some email!\n\n");

    char email[100], subject[50], message[500];
    int attempts, send = 0;

    printf("Please enter the recipient's email address: ");
    scanf("%s", email);

    printf("Please enter the subject of your email: ");
    scanf("%s", subject);

    printf("Please enter your message (less than 500 characters): ");
    scanf("%s", message);

    printf("\nSending email to %s with subject \"%s\" and message \"%s\"...\n", email, subject, message);

    for (attempts = 1; attempts <= 3; attempts++){
        int status = rand() % 2;

        if (status == 1){
            printf("Email sent successfully! Thank you for using the C Email Client.\n");
            send = 1;
            break;
        } else {
            printf("Error sending email. Retrying attempt %d...\n", attempts);
        }
    }

    if (send == 0){
        printf("Unable to send email after 3 attempts. Please try again later.\n");
    }

    return 0;
}