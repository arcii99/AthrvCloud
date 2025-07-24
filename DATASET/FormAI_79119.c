//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include<stdio.h>

int main() {
  printf("Wooohoooo! Let's have some fun with C Programming!\n");
  printf("First, let's declare some variables.\n");

  int num1 = 5;
  float num2 = 3.1415;
  char letter = 'C';
  char name[20] = "Happy Coder";
  
  printf("The value of num1 is %d\n", num1);
  printf("The value of num2 is %f\n", num2);
  printf("The letter is %c\n", letter);
  printf("The name is %s\n", name);

  printf("Now, let's do some calculations and make the results even happier!\n");
  int sum = num1 + num2;
  float diff = num1 - num2;
  
  printf("The sum of num1 and num2 is %d\n", sum);
  printf("The difference between num1 and num2 is %f\n", diff);
  
  printf("Let's make the output even more joyful by including some colors!\n");
  printf("\033[0;32m"); // set color to green
  printf("Congratulations, you are a happy C coder!\n");
  printf("\033[0m"); // reset color back to black

  printf("Now, it's your turn to code some happiness using C Programming!\n");
  
  return 0;
}