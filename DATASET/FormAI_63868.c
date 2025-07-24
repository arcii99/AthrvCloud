//FormAI DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

int main() {

  char message[] = "Hello, can you manipulate C strings?";
  char newMessage[50] = "";

  int length = strlen(message);
  int i;

  printf("Original message: %s\n", message);

  // Reversing the string
  for (i = length - 1; i >= 0; i--) {
    printf("%c", message[i]);
  }
  printf("\n");

  // Copying the string to a new array with all caps
  for (i = 0; i < length; i++) {
    newMessage[i] = toupper(message[i]);
  }
  printf("Uppercase message: %s\n", newMessage);

  // Finding and replacing a substring
  char search[] = "manipulate";
  char replace[] = "modify";
  char *ptr = strstr(message, search);
  if (ptr) {
    int index = ptr - message;

    memmove(&message[index + strlen(replace)],
            &message[index + strlen(search)],
            strlen(message) - index - strlen(search) + 1);
    memcpy(&message[index], replace, strlen(replace));

    printf("Replaced message: %s\n", message);
  }

  return 0;
}