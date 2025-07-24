//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sendEmail(char *to, char *subject, char *body){
    printf("\n Sending email to %s with subject '%s' and message body '%s'... \n", to, subject, body);
}

int main(){
    printf("Welcome to the Surrealist Email Client! \n\n");

    char to[100];
    char subject[100];
    char body[1000];
    int choice;

    while(1){
        printf("What would you like to do? \n\n");
        printf("1. Compose a new email \n");
        printf("2. Exit \n\n");

        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("\n To: ");
                getchar(); // to clear the newline character from the input buffer
                fgets(to, 100, stdin);
                
                printf(" Subject: ");
                fgets(subject, 100, stdin);
                
                printf(" Message body: ");
                fgets(body, 1000, stdin);
                
                sendEmail(to, subject, body);
                printf("\n Email sent successfully! \n\n");
                
                break;
            case 2:
                printf("\n Thank you for using the Surrealist Email Client! Goodbye. \n");
                exit(0);
            default:
                printf("\n Invalid choice. Please choose again. \n");
        }
    }

    return 0;
}