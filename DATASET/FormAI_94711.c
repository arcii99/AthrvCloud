//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  int length;
  char password[30];
  srand(time(0));
  printf("Enter the length of the password you need (6 - 25): ");
  scanf("%d", &length);
  if(length < 6 || length > 25) {
    printf("Invalid length!");
  }
  else {
    for(int i=0; i<length; i++) {
      int ch = rand() % 94 + 33;
      password[i] = (char) ch;
    }
    password[length] = '\0';
    printf("Your password is: %s\n", password);
  }
  return 0;
}