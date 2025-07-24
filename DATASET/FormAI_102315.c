//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readFortune(int fateNum) {
  switch(fateNum) {
    case 1:
      printf("Your future looks bright!\n");
      break;
    case 2:
      printf("You will meet someone special in the near future.\n");
      break;
    case 3:
      printf("Your hard work will pay off soon.\n");
      break;
    case 4:
      printf("Your future is uncertain. Stay vigilant.\n");
      break;
    case 5:
      printf("You may have a financial windfall coming your way.\n");
      break;
    case 6: 
      printf("A dark cloud is on the horizon. Be prepared.\n");
      break;
    case 7:
      printf("You will experience a major life change in the near future.\n");
      break;
    case 8:
      printf("You will receive a surprise gift soon.\n");
      break;
    case 9:
      printf("Your love life will take a new turn soon.\n");
      break;
    case 10:
      printf("You may have to make a tough decision soon.\n");
      break;
    default:
      printf("Sorry, your fate is unknown at this time.\n");
      break;
  }
}

void generateFortune() {
  srand(time(NULL));
  int fateNum = rand() % 10 + 1; // generates a random number between 1-10
  readFortune(fateNum);
}

int main() {
  printf("Welcome to the automated fortune teller!\n");
  printf("Press any key to generate your fate...\n");
  getchar();
  generateFortune();
  return 0;
}