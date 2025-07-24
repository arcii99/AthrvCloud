//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * This program generates two random numbers and asks the user
 * to get the quotient and remainder of the division of these numbers
 */

int main(){
  int num1, num2, quo, rem;
  srand(time(NULL));

  printf("Welcome to the Math Exercise Game!\n");
  printf("Are you ready to test your quotient and remainder skills?\n");
 
  // Generate two random numbers between 0 and 99
  num1 = rand() % 100;
  num2 = rand() % 100;
 
  printf("What is the quotient of %d divided by %d? ", num1*num2, num1);
  scanf("%d", &quo);
 
  // Check if the user's quotient is correct
  if(quo == num2){
    printf("Great job! You are a Math whiz!\n");
  }else{
    printf("Oops! That's not correct. The correct quotient is %d\n", num2);
  }
 
  printf("What is the remainder of %d divided by %d? ", num1*num2, num1);
  scanf("%d", &rem);
 
  // Check if the user's remainder is correct
  if(rem == 0){
    printf("You are on fire! You got the quotient and remainder both correct!\n");
  }else{
    printf("Oops! That's not correct. The correct remainder is %d\n", num1*num2 % num1);
  }
 
  printf("Thanks for playing the Math Exercise Game!\n");
 
  return 0;
}