//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {

  char sender[50], recipient[50], subject[100], body[2000];

  printf("Welcome to your inbox! Please enter your email information below:\n");
  printf("From: ");
  scanf("%s", sender);
  printf("To: ");
  scanf("%s", recipient);
  printf("Subject: ");
  fgets(subject, 100, stdin);
  printf("Body: ");
  fgets(body, 2000, stdin);

  printf("\nThank you! Your email has been sent...\n\n");

  printf("Dear %s,\n\n", recipient);
  printf("I hope this message finds you well. I wanted to personally reach out to you to let you know that your recent project caught my attention and I was really impressed with your work. I would like to discuss the possibility of working together on future projects.\n\n");
  printf("Please let me know if you are interested and we can set up a time to chat further.\n\n");
  printf("Thank you,\n%s\n\n", sender);

  return 0;
}