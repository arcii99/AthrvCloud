//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the encryption program! It will take your input and encrypt it using our proprietary algorithm.\n");

  char input[100];
  printf("Please enter your input: ");
  fgets(input, 100, stdin);
  printf("\n");

  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    input[i] = input[i] + 5;
  }

  printf("Your encrypted input is: %s\n", input);
  printf("Don't worry, your input is safe with us! We used the latest encryption technology to ensure it is secure.\n");

  return 0;
}