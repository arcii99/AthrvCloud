//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void checkIntrusion(char user_input[]) {
  char keywords[6][10] = {"master", "password", "root", "admin", "sudo", "access"};

  for (int i = 0; i < 6; i++) {
    if (strstr(user_input, keywords[i]) != NULL) {
      printf("Warning! Intrusion attempt detected!\n");
      exit(0);
    }
  }
}

int main() {
  char user_input[MAX_LENGTH];

  printf("Please enter your login credentials:\n");
  scanf("%[^\n]%*c", user_input);

  checkIntrusion(user_input);

  printf("Welcome to our portal, %s!\n", user_input);

  return 0;
}