//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Think of a question and press enter to receive an answer...\n");

  char userInput[100];
  fgets(userInput, sizeof(userInput), stdin);

  srand(time(NULL));
  int fortuneNum = rand() % 7;

  switch(fortuneNum) {
    case 0:
      printf("Your future looks bright. Keep working hard and stay motivated.\n");
      break;
    case 1:
      printf("Be patient, good things come to those who wait. Don't rush into anything.\n");
      break;
    case 2:
      printf("You will face a challenge soon, but have faith in yourself and you will overcome it.\n");
      break;
    case 3:
      printf("A new opportunity is coming your way. Be open-minded and embrace it.\n");
      break;
    case 4:
      printf("You need to let go of the past in order to move forward. Don't dwell on what you cannot change.\n");
      break;
    case 5:
      printf("Your relationships will be tested in the near future. Stay calm and communicate openly.\n");
      break;
    case 6:
      printf("Luck is on your side. Take some risks and follow your intuition.\n");
      break;
    default:
      printf("The stars are not aligning at this moment. Wait for a better time to ask your question.\n");
      break;
  }
  return 0;
}