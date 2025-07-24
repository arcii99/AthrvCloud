//FormAI DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 500
#define MAX_INPUT_LEN 100

typedef struct {
    char sender[MAX_EMAIL_LEN];
    char receiver[MAX_EMAIL_LEN];
    char subject[MAX_EMAIL_LEN];
    char body[MAX_EMAIL_LEN];
} Email;

void trim(char *str) {
    int len = strlen(str);
    
    while (len > 0 && isspace(str[len-1])) {
        str[--len] = '\0';
    }
    
    while (*str && isspace(*str)) {
        ++str;
        --len;
    }
    
    memmove(str, str + (str[0] == '-' && str[1] == '-') + (str[0] == ' ' && str[1] == ' '), len);
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    char input[MAX_INPUT_LEN];
    
    printf("\nWelcome to the Peaceful Email Client!\n\n");
    
    while (1) {
        printf("Enter your command:\n");
        fgets(input, MAX_INPUT_LEN, stdin);
        trim(input);
        
        if (strcmp(input, "compose") == 0) {
            if (num_emails == MAX_EMAILS) {
                printf("Sorry, you have reached the maximum number of emails (%d).\n", MAX_EMAILS);
                continue;
            }
            
            Email e;
            printf("\nFrom: ");
            fgets(e.sender, MAX_EMAIL_LEN, stdin);
            trim(e.sender);
            
            printf("To: ");
            fgets(e.receiver, MAX_EMAIL_LEN, stdin);
            trim(e.receiver);
            
            printf("Subject: ");
            fgets(e.subject, MAX_EMAIL_LEN, stdin);
            trim(e.subject);
            
            printf("Body:\n");
            fgets(e.body, MAX_EMAIL_LEN, stdin);
            trim(e.body);
            
            emails[num_emails++] = e;
            printf("Email composed successfully!\n\n");
        }
        else if (strcmp(input, "list") == 0) {
            if (num_emails == 0) {
                printf("Your inbox is empty.\n\n");
                continue;
            }
            
            printf("\nYour inbox contains %d emails:\n", num_emails);
            
            for (int i = 0; i < num_emails; ++i) {
                printf("\n%d. Subject: %s\n   From: %s\n   To: %s\n   Message: %s\n", 
                       i+1,
                       emails[i].subject, 
                       emails[i].sender,
                       emails[i].receiver,
                       emails[i].body);
            }
            
            printf("\n");
        }
        else if (strcmp(input, "view") == 0) {
            if (num_emails == 0) {
                printf("Your inbox is empty.\n\n");
                continue;
            }
            
            printf("\nEnter the number of the email you want to view:\n");
            fgets(input, MAX_INPUT_LEN, stdin);
            int num = atoi(input);
            
            if (num < 1 || num > num_emails) {
                printf("Invalid email number. Please enter a number between 1 and %d.\n\n", num_emails);
                continue;
            }
            
            printf("\nSubject: %s\nFrom: %s\nTo: %s\nMessage: %s\n\n", 
                   emails[num-1].subject, 
                   emails[num-1].sender, 
                   emails[num-1].receiver, 
                   emails[num-1].body);
        }
        else if (strcmp(input, "quit") == 0) {
            printf("\nThank you for using the Peaceful Email Client!\n\n");
            break;
        }
        else {
            printf("Invalid command. Please enter one of the following commands: compose, list, view, quit\n\n");
        }
    }
    
    return 0;
}