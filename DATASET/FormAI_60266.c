//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  char keyword[] = "banana";
  int count = 0;

  printf("What's on your mind?");
  fgets(message, 100, stdin);

  // Count how many times "banana" appears in the message
  char *ptr = message;
  while ((ptr = strstr(ptr, keyword)) != NULL) {
    count++;
    ptr++;
  }

  printf("\nI see you've mentioned bananas %d times. Let's fix that!", count);

  // Replace all instances of "banana" with "potato"
  char new_message[200] = "";
  char *token = strtok(message, " ");
  while (token != NULL) {
    if (strcmp(token, keyword) == 0) {
      strcat(new_message, "potato ");
    } else {
      strcat(new_message, token);
      strcat(new_message, " ");
    }
    token = strtok(NULL, " ");
  }
  printf("\nYour new message is: %s", new_message);

  // Let's add some flair!
  printf("\nDid you know that bananas make great phone cases? Let me show you!\n\n");

  printf("         .-^-.\n");
  printf("       .'=^=^='.\n");
  printf("      /=^=^=^=^=\\    \n");
  printf("      :^=:=:=:=:^;   \n");
  printf("       \\=^=^=^=/\n");
  printf("        '._|_.'\n");

  printf("\nTada! Your phone is now protected by the power of bananas.\n");

  return 0;
}