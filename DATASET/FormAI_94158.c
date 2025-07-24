//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int length;
  printf("Enter the length of the password: ");
  scanf("%d", &length);

  char password[length+1];
  srand(time(0));

  for (int i=0; i<length; i++) {
    int randomNum = rand() % 82;
    if (randomNum < 10) {
      password[i] = randomNum + 48;
    }
    else if (randomNum < 36) {
      password[i] = randomNum + 55;
    }
    else {
      password[i] = randomNum + 61;
    }
  }

  password[length] = '\0';

  printf("Generated password: %s\n", password);

  return 0;
}