//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>

void recoverData() {
  /* Code to recover data */
  printf("Success! Data has been recovered.\n");
}

int main() {
  char input;
  printf("Welcome to the Medieval Data Recovery Tool!\n");
  printf("Press the magic button to start the recovery process: ");
  scanf("%c", &input);
  if (input == 'x') {
    recoverData();
  } else {
    printf("Sorry, the magic button was not pressed. The recovery process cannot begin.\n");
  }
  return 0;
}