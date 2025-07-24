//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include<stdio.h>

void generateRandomNumber(int *, int);

void displayFortune(int);

int main()
{
  int randomNumber;
  
  // Maximum number of fortunes 
  int maxFortuneNumber = 5; 
   
  // Generating a Random number on which Fortune is based
  generateRandomNumber(&randomNumber, maxFortuneNumber); 
 
  // Displaying the Fortune based on the random number generated
  displayFortune(randomNumber); 
 
  return 0;
}

void generateRandomNumber(int *num, int max)
{
  srand(time(0));
  *num = (rand() % max) + 1;
}

void displayFortune(int num)
{
  switch(num)
  {
    case 1:
      printf("Your future looks bright! You will soon receive great news.\n");
      break;
    case 2:
      printf("You will travel to a distant land and meet someone very important.\n");
      break;
    case 3:
      printf("You will get a big promotion at work and your colleagues will be envious.\n");
      break;
    case 4:
      printf("You will meet your soulmate soon and they will bring a lot of joy into your life.\n");
      break;
    case 5:
      printf("You will receive unexpected wealth and your financial situation will improve greatly.\n");
      break;
    default:
      printf("Invalid Fortune Number");
      break;
  }
}