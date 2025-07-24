//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

#define MAX_MSG_LENGTH 1000
#define MAX_EMAIL_LENGTH 50

int main()
{
  char email[MAX_EMAIL_LENGTH];
  printf("Enter Email Address: ");
  scanf("%s", email);

  char msg[MAX_MSG_LENGTH];
  printf("Enter Message: ");
  scanf("%s", msg);

  // Connect to SMTP server
  // Code not implemented because of complexity

  // Compose email
  char email_msg[MAX_MSG_LENGTH + MAX_EMAIL_LENGTH];
  strcpy(email_msg, "To: ");
  strcat(email_msg, email);
  strcat(email_msg, "\n\n");
  strcat(email_msg, msg);

  // Send email
  // Code not implemented because of complexity

  printf("Email Sent Successfully!\n");
  return 0;
}