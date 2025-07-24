//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayFortune(int fortuneNumber);

int main(){
  int fortuneNumber;
  srand(time(0));
  
  printf("Welcome to the Automated Fortune Teller!\n\n");
  printf("Please think of a number between 1 and 10 and type it in: ");
  
  scanf("%d", &fortuneNumber);
  
  if(fortuneNumber < 1 || fortuneNumber > 10){
    printf("Invalid number entered. Please try again with a number between 1 and 10.\n");
    return;
  }
  
  displayFortune(fortuneNumber);
  
  printf("Thank you for using the Automated Fortune Teller!\n\n");
  
  return 0;
}

void displayFortune(int fortuneNumber){
  switch(fortuneNumber){
    case 1:
      printf("You will have a great day today!\n");
      break;
    case 2:
      printf("You will meet someone special today!\n");
      break;
    case 3:
      printf("Financial prosperity is on the horizon for you!\n");
      break;
    case 4:
      printf("Your future is full of adventure and excitement!\n");
      break;
    case 5:
      printf("A loved one will surprise you with a thoughtful gift!\n");
      break;
    case 6:
      printf("You will conquer a difficult problem with ease!\n");
      break;
    case 7:
      printf("A new opportunity is waiting for you just around the corner!\n");
      break;
    case 8:
      printf("Your hard work will pay off soon. Keep pushing!\n");
      break;
    case 9:
      printf("You will make a new friend today!\n");
      break;
    case 10:
      printf("Success is coming your way. Be ready for it!\n");
      break;
  }
  
  printf("\nHere's a bonus fortune for you: ");
  
  int randomNumber = rand() % 5 + 1;
  
  switch(randomNumber){
    case 1:
      printf("You will go on a wonderful trip soon!\n");
      break;
    case 2:
      printf("You will receive unexpected good news soon!\n");
      break;
    case 3:
      printf("You will find a solution to a problem that has been troubling you!\n");
      break;
    case 4:
      printf("You will make a new friendship that will last a lifetime!\n");
      break;
    case 5:
      printf("You will overcome a fear and feel stronger for it!\n");
      break;
  }
}