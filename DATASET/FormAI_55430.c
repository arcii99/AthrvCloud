//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include<stdio.h>

int main(){
  printf("Welcome to the Happy C program!\n");

  int num1, num2, result; // declaring variables
  printf("Enter first number: ");
  scanf("%d", &num1); // getting input from user
  printf("Enter second number: ");
  scanf("%d", &num2); // getting input from user

  result = num1 + num2; // adding the two numbers
  printf("The sum of %d and %d is %d\n", num1, num2, result); // displaying the result

  if(result > 10){
     printf("Wow, that's a big number!\n");
  }else{
     printf("Oh, that's not so big...\n");
  }

  char name[20]; // declaring a character array
  printf("What's your name?: ");
  scanf("%s", name); // getting name from user
  printf("Hello, %s! Hope you're having a great day!\n", name); // welcoming the user

  printf("Now let's count from 1 to 10!\n");
  for(int i = 1; i <= 10; i++){
     printf("%d ", i); // display numbers from 1 to 10
  }
  printf("\nFinished counting! Yay!\n");

  return 0;
}