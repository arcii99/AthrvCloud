//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

int main() {
  printf("Welcome to the C Tutorials: How to Write a Chatbot Program\n");
  printf("In this tutorial, we will learn how to create a simple chatbot program using C language\n");
  printf("First, let's start by asking the user their name\n");

  char name[50];
  printf("What is your name? ");
  scanf("%s", name);
  printf("Hello %s! How can I assist you today?\n", name);

  char message[200];
  printf("Please type your message: ");
  scanf("\n%[^\t\n]s", message);

  // Responses to User Messages
  if (strstr(message, "hello") != NULL || strstr(message, "hi") != NULL) {
    printf("Hello there!\n");
  } else if (strstr(message, "how are you") != NULL) {
    printf("I'm doing great! How about you?\n");
  } else if (strstr(message, "goodbye") != NULL || strstr(message, "bye") != NULL) {
    printf("Goodbye! Have a great day!\n");
  } else {
    printf("Sorry, I did not understand your message.\n");
  }

  return 0;
}