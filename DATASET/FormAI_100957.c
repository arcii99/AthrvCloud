//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char userName[50];
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please enter your name: ");
  scanf("%s", userName);
  printf("\nHello %s!\n", userName);

  srand(time(NULL));

  int randNum = rand() % 4;

  if (randNum == 0) {
    printf("You will receive some good news today!\n");
  } else if (randNum == 1) {
    printf("Be careful while driving today.\n");
  } else if (randNum == 2) {
    printf("You will receive help from a friend today.\n");
  } else {
    printf("You will have a successful day at work!\n");
  }

  return 0;
}