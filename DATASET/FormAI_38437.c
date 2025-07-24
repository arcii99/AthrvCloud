//FormAI DATASET v1.0 Category: Email Client ; Style: imaginative
#include<stdio.h>
#include<string.h>

struct email {
    char sender[50];
    char subject[100];
    char body[500];
};

void sendEmail(struct email e, char recipient[]) {
    printf("From: %s\n", e.sender);
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", e.subject);
    printf("---------------------\n");
    printf("%s\n", e.body);
    printf("---------------------\n");
    printf("Email sent successfully!\n");
}

int main() {
    struct email e;

    strcpy(e.sender, "johndoe@gmail.com");
    strcpy(e.subject, "Greetings from C Email Client!");
    strcpy(e.body, "Hello there! This email is being sent through a C email client program that I wrote. Pretty cool, huh?");

    sendEmail(e, "janedoe@yahoo.com");

    return 0;
}