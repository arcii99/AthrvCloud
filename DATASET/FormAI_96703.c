//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(void) {
  char email_address[MAX_BUFFER_SIZE], email_subject[MAX_BUFFER_SIZE], email_body[MAX_BUFFER_SIZE];

  printf("Enter recipient email address: ");
  fgets(email_address, MAX_BUFFER_SIZE, stdin);

  printf("Enter email subject: ");
  fgets(email_subject, MAX_BUFFER_SIZE, stdin);

  printf("Enter email body: ");
  fgets(email_body, MAX_BUFFER_SIZE, stdin);

  printf("Sending email to %s with subject '%s' and body '%s'... \n", email_address, email_subject, email_body);

  printf("Email sent successfully! \n");

  return 0;
}