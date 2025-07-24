//FormAI DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>

int main() {
    // Declare variables 
    char recipient[100];
    char subject[100];
    char body[1000];
    
    // Prompt user for recipient
    printf("My dearest one, please enter the email address of your love: ");
    scanf("%s", recipient);
    
    // Prompt user for subject
    printf("My sweet one, please enter the subject of your love-filled email: ");
    scanf("%s", subject);
    
    // Prompt user for body
    printf("My beloved one, please enter the content of your love-filled email: ");
    scanf("%s", body);
    
    // Send email
    printf("My love, your email has been sent to %s with the subject \"%s\" and the following message: %s\n", recipient, subject, body);
    
    return 0;
}