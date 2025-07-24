//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Welcome to the surreal IMAP client experience\n");
    printf("Please enter your email ID: ");
    char email[100];
    scanf("%s", email);
    printf("\nConnecting to IMAP server...");
    sleep(3);
    printf("\nConnected!\n");
    printf("*************************\n");
    printf("*     INBOX (1)        *\n");
    printf("*     SENT MAIL (2)    *\n");
    printf("*     TRASH (3)        *\n");
    printf("*************************\n");
    printf("Please enter your choice (1/2/3): ");
    int choice;
    scanf("%d", &choice);
    printf("\nFetching mails from selected folder...");
    sleep(4);
    printf("\n\nMail 1:\nFrom: surrealbot@weirdmail.com\nTo: %s\nSubject: The universe is a simulation\n\nDear %s,\n\nI am writing to inform you that the universe is a simulation and we are all characters in a computer program. Pretty surreal, huh?\n\nBest regards,\nSurrealbot\n\n", email, email);
    printf("\n\nMail 2:\nFrom: dreamweaver@mail.net\nTo: %s\nSubject: Re: The universe is a simulation\n\nHi %s,\n\nI saw your email about the universe being a simulation. Have you been smoking some of that weird stuff again? Haha! Just kidding. But seriously, don't believe everything you read.\n\nCheers,\nDreamweaver\n\n", email, email);
    printf("\n\nMail 3:\nFrom: kafkaesque@absurdmail.com\nTo: %s\nSubject: Metamorphosis update\n\nDear %s,\n\nI hope this email finds you well. Just wanted to let you know that I have made some progress on my new novel, Metamorphosis. It's about a man who wakes up one day as a giant bug. I think it's going to be a hit!\n\nYours truly,\nKafkaesque\n\n", email, email);
    printf("\n\nEnd of mails.\n");
    printf("Closing connection...");
    sleep(3);
    printf("\n\nDisconnected.\n");
    printf("Thank you for using the surreal IMAP client.\n");
    return 0;
}