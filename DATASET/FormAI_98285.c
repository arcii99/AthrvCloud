//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

  char message[] = "Knock knock";

  printf("Q: %s?\n", message);
  printf("A: ");

  // swap every other letter in the response
  for(int i = 0; i < strlen(message); i++) {
    printf("%c", (i % 2 == 0 ? message[i+1] : message[i-1]));
  }
  printf("!\n");

  // now let's reverse the original message
  printf("Original message: %s\n", message);
  int len = strlen(message);
  for(int i = 0; i < len/2; i++) {
    char temp = message[i];
    message[i] = message[len-i-1];
    message[len-i-1] = temp;
  }
  printf("Reverse message: %s\n", message);

  // finally, let's mix it up and only print every second character
  printf("Messed up message: ");
  for(int i = 0; i < strlen(message); i++) {
    if(i % 2 == 0) printf("%c", message[i]);
  }
  printf("\n");

  return 0;
}