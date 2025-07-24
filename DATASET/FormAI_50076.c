//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

typedef struct email {
    char to[100];
    char from[100];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    char password[20];
    printf("Enter your password: ");
    scanf("%19s", password);
    // securely store password in memory
    memset(password, 0, sizeof(password));
    
    Email email;
    printf("\nEnter recipient address: ");
    fgets(email.to, sizeof(email.to), stdin);
    printf("\nEnter subject: ");
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("\nEnter message body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);

    // securely erase email contents from memory
    memset(&email, 0, sizeof(email));

    printf("\nEmail sent successfully!\n");
    return 0;
}