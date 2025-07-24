//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed
  
  printf("\nWelcome to the Automated Fortune Teller!\n");
  printf("Please ask a question and press enter to receive your answer.\n");
  
  char question[100]; //define character array to store user's question
  scanf("%[^\n]", question); //accept input from user until enter key is pressed
  
  //generate random number between 1 and 4
  int random_num = rand() % 4 + 1;
  
  //use random number to determine fortune
  switch(random_num){
    case 1:
      printf("\nYour fortune is looking good!\n");
      break;
    case 2:
      printf("\nYour future is uncertain. Try again later.\n");
      break;
    case 3:
      printf("\nThings may not go as planned, but don't lose hope!\n");
      break;
    case 4:
      printf("\nYour path is bright and full of possibilities!\n");
      break;
    default:
      printf("\nOops! Something went wrong. Please try again.\n");
      return 0;
  }
  
  return 0;
}