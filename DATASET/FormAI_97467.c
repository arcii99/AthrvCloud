//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[50];
  printf("Welcome to the Automated Fortune Teller.\n");
  printf("Please enter your name: ");
  fgets(name, sizeof(name), stdin);
  
  srand(time(NULL)); // initialize random number generator
  
  // generate random number between 1 and 5
  int fortune = rand() % 5 + 1;
  
  switch(fortune) {
    case 1:
      printf("%s, you will have a happy and successful year.\n", name);
      break;
    case 2:
      printf("%s, you will face some challenges, but you will overcome them.\n", name);
      break;
    case 3:
      printf("%s, you may experience some unexpected changes, but they will lead to growth.\n", name);
      break;
    case 4:
      printf("%s, the universe is aligning in your favor.\n", name);
      break;
    case 5:
      printf("%s, listen to your intuition and trust the process.\n", name);
      break;
    default:
      printf("%s, an error has occurred.\n", name);
      break;
  }
  
  return 0;
}