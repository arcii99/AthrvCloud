//FormAI DATASET v1.0 Category: Email Client ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Welcome to the Happy Email Client!\n");
  char sender[50], recipient[50], subject[100], message[500];
  printf("Enter sender email address: ");
  scanf("%s", sender);
  printf("Enter recipient email address: ");
  scanf("%s", recipient);
  printf("Enter email subject: ");
  scanf("%s", subject);
  printf("Enter message: ");
  scanf("%s", message);
  printf("\n\n\nSending email....\n\n\n");
  printf("To: %s\n", recipient);
  printf("From: %s\n", sender);
  printf("Subject: %s\n", subject);
  printf("Message: %s\n", message);
  printf("\n\n\nEmail sent successfully!\n\n\n");
  return 0;
}