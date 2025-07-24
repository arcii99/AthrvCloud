//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 50
#define MAX_SUBJECT_SIZE 100
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_SIZE];
    char message[MAX_MESSAGE_SIZE];
} Email;

int main() {
    Contact list[MAX_EMAILS];
    Email email;
    int numContacts = 0;
    
    FILE *fpIn = fopen("contacts.txt", "r");
    if(fpIn == NULL) {
        printf("Error: could not open contacts.txt\n");
        exit(1);
    }
    
    char buffer[MAX_NAME_SIZE+MAX_EMAIL_SIZE+2];
    while(fgets(buffer, MAX_NAME_SIZE+MAX_EMAIL_SIZE+2, fpIn) != NULL) {
        char *name = strtok(buffer, ",");
        char *email = strtok(NULL, "\n");
        if(name != NULL && email != NULL) {
            strcpy(list[numContacts].name, name);
            strcpy(list[numContacts].email, email);
            numContacts++;
        }
    }
    fclose(fpIn);
    
    char recipient[MAX_EMAIL_SIZE];
    printf("Enter recipient email address: ");
    fgets(recipient, MAX_EMAIL_SIZE, stdin);
    recipient[strcspn(recipient, "\n")] = 0;
    
    int i;
    for(i=0; i<numContacts; i++) {
        if(strcmp(list[i].email, recipient) == 0) {
            printf("To: %s <%s>\n", list[i].name, recipient);
            break;
        }
    }
    if(i == numContacts) {
        printf("Recipient not found in mailing list.\n");
        exit(1);
    }
    
    printf("Enter subject: ");
    fgets(email.subject, MAX_SUBJECT_SIZE, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0;
    
    printf("Enter message (press Ctrl-D to end):\n");
    fgets(email.message, MAX_MESSAGE_SIZE, stdin);
    email.message[strcspn(email.message, "\n")] = 0;
    
    char filename[MAX_EMAIL_SIZE+5];
    sprintf(filename, "%s.txt", recipient);
    FILE *fpOut = fopen(filename, "w");
    if(fpOut == NULL) {
        printf("Error: could not create email file\n");
        exit(1);
    }
    
    fprintf(fpOut, "From: %s <%s>\n", list[i].name, list[i].email);
    fprintf(fpOut, "To: %s <%s>\n", list[i].name, recipient);
    fprintf(fpOut, "Subject: %s\n", email.subject);
    fprintf(fpOut, "\n");
    fprintf(fpOut, "%s", email.message);
    
    fclose(fpOut);
    
    printf("Email successfully sent to %s\n", recipient);
    
    return 0;
}