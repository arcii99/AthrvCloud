//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Automated Fortune Teller.\n\n");

  // Romeo's fortune
  printf("Romeo, please ask a yes or no question: ");
  char romeo_question[50];
  fgets(romeo_question, 50, stdin);
  srand(time(0) + 1);
  int romeo_fortune = rand() % 2;
  if (romeo_fortune == 0) {
    printf("\nJuliet says: Nay, you shall not find love with that question in mind.\n");
  } else {
    printf("\nJuliet says: Aye, fate shall bring you what you desire.\n");
  }

  // Juliet's fortune
  printf("\n\nJuliet, please ask a yes or no question: ");
  char juliet_question[50];
  fgets(juliet_question, 50, stdin);
  srand(time(0) - 1);
  int juliet_fortune = rand() % 2;
  if (juliet_fortune == 0) {
    printf("\nRomeo says: Nay, that shall not come to pass.\n");
  } else {
    printf("\nRomeo says: Aye, your dreams shall come true.\n");
  }

  return 0;
}