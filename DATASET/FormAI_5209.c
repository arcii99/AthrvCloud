//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Happy Email Client!\n\n");
    
    // Get user input
    char recipient[100], subject[100], body[500];
    printf("Enter recipient's email address: ");
    scanf("%s", recipient);
    printf("Enter email subject line: ");
    scanf("%s", subject);
    printf("Enter email body (max 500 characters): ");
    scanf("%s", body);
    
    // Send the email
    printf("\nHappy day! Your email has been sent to %s.\n\n", recipient);
    
    return 0;
}