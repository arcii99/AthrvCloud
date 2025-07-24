//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200
#define MAX_EMAILS 100

// Define the email structure
typedef struct {
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
  char recipient_email[50];
} Email;

// Define the client function
int main(void) {
  Email emails[MAX_EMAILS];
  int i, num_emails = 0; // Initialize the number of emails to 0
  char user_choice = ' ';
  do {
    // Prompt the user for the information to send the email
    printf("Enter the email receiver's email address:\n");
    scanf("%s", emails[num_emails].recipient_email);
    printf("Enter the email subject:\n");
    scanf("%s", emails[num_emails].subject);
    printf("Enter the email body:\n");
    scanf("%s", emails[num_emails].body);
    
    // Prompt the user to send more emails or not
    printf("Do you want to send another email? (Y/N)\n");
    scanf(" %c", &user_choice);
    num_emails++;
  } while(user_choice == 'Y' && num_emails < MAX_EMAILS);
  
  printf("\nYou have composed the following emails:\n\n");
  
  // Print all the emails composed by the user
  for(i = 0; i < num_emails; i++) {
    printf("EMAIL %d\n", i+1);
    printf("Recipient email: %s\n", emails[i].recipient_email);
    printf("Subject: %s\n", emails[i].subject);
    printf("Body: %s\n", emails[i].body);
    printf("------------------------\n");
  }
  
  return 0;
}