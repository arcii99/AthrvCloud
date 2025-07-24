//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>

void errorHandling(){
  printf("Oops! Something went wrong!\n");
}

int main(){
  
  char userInput[50];
  int num1, num2, result;

  printf("Welcome to Curious Error Handling Program!\n");

  printf("Please enter the first number for division:\n");
  if(scanf("%d", &num1) == 0){
    errorHandling();
    return 0;
  }

  printf("Please enter the second number for division:\n");
  if(scanf("%d", &num2) == 0 || num2 == 0){
    errorHandling();
    return 0;
  }

  result = num1 / num2;

  printf("The result of division is: %d\n", result);

  printf("Please enter a word:\n");
  scanf("%s", userInput);

  if(userInput[0] == 'c' || userInput[0] == 'C'){
    printf("You wrote the letter C. How curious!\n");
  }
  else{
    printf("You did not write the letter C. How curious!\n");
  }

  printf("Program executed successfully!\n");

  return 0;
}