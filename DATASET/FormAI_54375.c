//FormAI DATASET v1.0 Category: Email Client ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct email{
    char* sender;
    char* recipient;
    char* subject;
    char* message;
};

void readEmail(struct email* em){
    char temp[1000];
    printf("From: ");
    fgets(temp, 1000, stdin);
    em->sender = (char*)malloc(strlen(temp) * sizeof(char));
    strcpy(em->sender, temp);

    printf("To: ");
    fgets(temp, 1000, stdin);
    em->recipient = (char*)malloc(strlen(temp) * sizeof(char));
    strcpy(em->recipient, temp);

    printf("Subject: ");
    fgets(temp, 1000, stdin);
    em->subject = (char*)malloc(strlen(temp) * sizeof(char));
    strcpy(em->subject, temp);

    printf("Message: ");
    fgets(temp, 1000, stdin);
    em->message = (char*)malloc(strlen(temp) * sizeof(char));
    strcpy(em->message, temp);
}

void printEmail(struct email em){
    printf("From: %s", em.sender);
    printf("To: %s", em.recipient);
    printf("Subject: %s", em.subject);
    printf("Message: %s", em.message);
}

int main(){
    struct email em;
    readEmail(&em);
    printEmail(em);
    return 0;
}