//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  char spam[100];
  printf("Please enter a message: ");
  fgets(spam, 100, stdin);
  
  int i, count = 0;
  char* bannedWords[] = {"buy", "cheap", "offer"};
  
  for (i = 0; i < 3; i++) {
    if (strstr(spam, bannedWords[i]) != NULL) {
      count++;
    }
  }
  
  if (count > 0) {
    printf("Warning! This message contains %d spam word(s).\n", count);
    printf("Please edit your message and send it again.\n");
  } else {
    printf("Your message has been sent successfully.\n");
  }
  
  return 0;
}