//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct Email {
  char sender[50];
  char receiver[50];
  char subject[100];
  char body[500];
};

int main() {
  struct Email email;
  
  // Get user input
  printf("Enter sender email address: ");
  scanf("%s", email.sender);
  
  printf("Enter receiver email address: ");
  scanf("%s", email.receiver);
  
  printf("Enter email subject: ");
  scanf("%s", email.subject);
  
  printf("Enter email body: ");
  scanf("%s", email.body);
  
  // Print email details
  printf("\nSender: %s", email.sender);
  printf("\nReceiver: %s", email.receiver);
  printf("\nSubject: %s", email.subject);
  printf("\nBody: %s", email.body);
  
  // Send email functionality goes here
  
  return 0;
}