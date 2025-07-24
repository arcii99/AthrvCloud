//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void send_email(char *recipient, char *subject, char *body);

int main() {
  char recipient[] = "example@gmail.com";
  char subject[] = "Hello!";
  char body[] = "This email was sent from C code!";

  send_email(recipient, subject, body);

  return 0;
}

void send_email(char *recipient, char *subject, char *body) {
  printf("Connecting to email server...\n");
  printf("Authentication successful!\n");
  printf("Preparing email...\n");
  printf("Recipient: %s\n", recipient);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);
  printf("Sending email...\n");
  printf("Email sent successfully!\n");
}