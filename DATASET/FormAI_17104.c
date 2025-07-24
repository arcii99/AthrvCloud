//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>

int main() {
  int luckyNumber = 7;
  printf("I am a daring program that will guess your lucky number. Think of a number between 1 and 10.\n"); 
  printf("Is your lucky number %d? (y/n)\n", luckyNumber);
  char userInput = getchar();
  
  if (userInput == 'y') {
    printf("Hooray! I knew it. I'm the best program in the world!\n"); 
  } 
  else if (userInput == 'n') {
    printf("Boo! I'll get it next time. Let's try again...\n");
    printf("Is your lucky number higher or lower than %d? (h/l)\n", luckyNumber);
    userInput = getchar();
    
    if (userInput == 'h') {
      printf("Ok, your lucky number is higher than %d. Let's try again...\n", luckyNumber);
      int newLuckyNumber = (luckyNumber + 10) / 2; // Brave move: guessing halfway between 7 and 10
      printf("Is your lucky number %d? (y/n)\n", newLuckyNumber);
      userInput = getchar();
      
      if (userInput == 'y') {
        printf("Yes! I knew it all along.\n");
      } else {
        printf("Darn, I'll get it next time.\n");
      }
    } else if (userInput == 'l') {
      printf("Ok, your lucky number is lower than %d. Let's try again...\n", luckyNumber);
      int newLuckyNumber = (luckyNumber + 1) / 2; // Brave move: guessing halfway between 1 and 7
      printf("Is your lucky number %d? (y/n)\n", newLuckyNumber);
      userInput = getchar();
      
      if (userInput == 'y') {
        printf("Yes! I knew it all along.\n");
      } else {
        printf("Darn, I'll get it next time.\n");
      }
    } else {
      printf("I'm sorry, I didn't understand that input.\n");
    }
  } else {
    printf("I'm sorry, I didn't understand that input.\n");
  }
  return 0; 
}