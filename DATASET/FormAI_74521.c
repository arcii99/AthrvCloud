//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char message[100] = "You are the love of my life.";
  char name[20];

  printf("Enter your name: ");
  scanf("%s", name);

  // Combine the name to the message
  strcat(message, " ");
  strcat(message, name);
  strcat(message, ", ");
  strcat(message, "my heart beats only for you.\n");

  // Find the length of the message
  int len = strlen(message);

  // Reverse the message
  for (int i = 0; i < len / 2; i++) {
    char temp = message[i];
    message[i] = message[len - 1 - i];
    message[len - 1 - i] = temp;
  }

  // Replace "love" with "adore"
  char *love = "love";
  char *adore = "adore";
  char *ptr = strstr(message, love);
  int index = ptr - message;
  if (ptr != NULL) {
    strncpy(&message[index], adore, strlen(adore));
    memmove(&message[index + strlen(adore)], &message[index + strlen(love)], strlen(&message[index + strlen(love)]) + 1);
  }

  // Print the final message
  printf("%s", message);

  return 0;
}