//FormAI DATASET v1.0 Category: Email Client ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char name[50];
  char email[50];
} Contact;

typedef struct {
  char sender[50];
  Contact recipients[10];
  int numRecipients;
  char subject[100];
  char body[500];
} Email;

int sendEmail(Email email) {
  // Code to send email goes here
  printf("Email sent!\n");
  return 1;
}

int main() {
  Email newEmail;
  strcpy(newEmail.sender, "me@example.com");

  // Add some recipients
  Contact recipient1 = {"Bob", "bob@example.com"};
  newEmail.recipients[0] = recipient1;
  
  Contact recipient2 = {"Joe", "joe@example.com"};
  newEmail.recipients[1] = recipient2;
  
  newEmail.numRecipients = 2;
  
  // Add subject and body
  strcpy(newEmail.subject, "Test email");
  strcpy(newEmail.body, "Hello,\n\nThis is a test email.");

  // Send email
  sendEmail(newEmail);

  return 0;
}