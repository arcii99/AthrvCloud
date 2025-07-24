//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

int main(void) {
  char input[MAX_INPUT_LEN];
  char trigger[] = "root";
  int attempts = 0;
  int max_attempts = 3;

  while (1) {
    printf("Enter your username: ");
    fflush(stdout);

    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strstr(input, trigger)) {
      attempts++;

      if (attempts >= max_attempts) {
        printf("INTRUSION DETECTED: Too many failed attempts\n");
        exit(EXIT_FAILURE);
      }

      printf("INTRUSION ALERT: Unauthorized user\n");
      continue;
    }

    printf("Welcome, %s\n", input);
    break;
  }

  printf("Program execution complete.\n");
  return 0;

}