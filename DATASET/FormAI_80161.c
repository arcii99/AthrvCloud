//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char ques[100];  // question input string
  int num;         // random number between 1 and 10
  char fortune[3][100] = {"Yes, definitely.", "No, definitely not.", "I'm sorry, I cannot answer that."}; // array of fortunes
 
  srand(time(NULL));  // seed the random number generator

  printf("Welcome to the Automated Fortune Teller!\n\n");
   
  while(1)
  {
    printf("What is your yes or no question?\n");
    fgets(ques, 100, stdin); // get question input from user
    num = rand() % 10 + 1; // generate random number between 1 and 10
    
    if(num < 4)
    {
      printf("%s\n\n", fortune[0]); // if the number is 1, 2 or 3, print the first fortune
    }
    else if(num > 7)
    {
      printf("%s\n\n", fortune[1]); // if the number is 8, 9 or 10, print the second fortune
    }
    else
    {
      printf("%s\n\n", fortune[2]); // if the number is between 4 and 7, print the third fortune
    }
   
    printf("Would you like to ask another question? (y/n)\n");
    char response;
    scanf("%c", &response); // get user response to continue or not
   
    if(response != 'y')
    {
      printf("Thank you for using the Automated Fortune Teller!\n");
      break; // if user does not enter 'y', exit the program
    }
    
    getchar(); // clear input buffer before next iteration of while loop 
  }
  
  return 0; 
}