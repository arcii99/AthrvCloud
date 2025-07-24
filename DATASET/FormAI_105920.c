//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT 128
#define MAX_EMAIL 1024

// function prototypes
void sendEmail(char *from, char *to, char *subject, char *message);

int main()
{
  char from[MAX_EMAIL];
  char to[MAX_EMAIL];
  char subject[MAX_SUBJECT];
  char message[MAX_EMAIL];
  
  // get email details
  printf("From: ");
  fgets(from, MAX_EMAIL, stdin);
  printf("To: ");
  fgets(to, MAX_EMAIL, stdin);
  printf("Subject: ");
  fgets(subject, MAX_SUBJECT, stdin);
  printf("Message: ");
  fgets(message, MAX_EMAIL, stdin);
  
  // remove newline characters
  from[strcspn(from, "\n")] = 0;
  to[strcspn(to, "\n")] = 0;
  subject[strcspn(subject, "\n")] = 0;
  message[strcspn(message, "\n")] = 0;
  
  // send email
  sendEmail(from, to, subject, message);
  
  return 0;
}

// function to send email
void sendEmail(char *from, char *to, char *subject, char *message)
{
  // code to send email goes here
  printf("Email sent from %s to %s with subject '%s'\n", from, to, subject);
}