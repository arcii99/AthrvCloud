//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    
    while (1) {
        // Prompt user for subject
        char subject[MAX_SUBJECT_LENGTH];
        printf("Enter email subject (or type 'quit' to exit): ");
        fgets(subject, MAX_SUBJECT_LENGTH, stdin);
        if (strcmp(subject, "quit\n") == 0) {
            break;
        }
        // Remove newline character from end of subject
        subject[strcspn(subject, "\n")] = 0;
        
        // Prompt user for body
        char body[MAX_BODY_LENGTH];
        printf("Enter email body: ");
        fgets(body, MAX_BODY_LENGTH, stdin);
        // Remove newline character from end of body
        body[strcspn(body, "\n")] = 0;
        
        // Add email to array
        Email new_email;
        strcpy(new_email.subject, subject);
        strcpy(new_email.body, body);
        emails[num_emails] = new_email;
        num_emails++;
        
        printf("Email sent!\n");
        printf("----------------------\n");
    }
    
    // Print all emails
    printf("\nHere are your sent emails:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("[%d] Subject: %s\n", i+1, emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("----------------------\n");
    }
    
    return 0;
}