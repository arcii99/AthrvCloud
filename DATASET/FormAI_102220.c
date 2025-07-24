//FormAI DATASET v1.0 Category: Random ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initializing random seed
  
  printf("Hi, I am a cheerful C program that generates random numbers!\n");
  
  int num1 = rand(); //first random number
  printf("The first number I generated is: %d \n", num1);
  
  int num2 = rand(); //second random number
  printf("The second number I generated is: %d \n", num2);
  
  int num3 = rand(); //third random number
  printf("The third number I generated is: %d \n", num3);
  
  int sum = num1 + num2 + num3; //sum of three random numbers
  printf("The sum of all three numbers is: %d \n", sum);
  
  float average = (float) sum / 3; //average of three random numbers
  printf("The average of all three numbers is: %.2f \n", average);
  
  int max = num1; //finding the maximum of three random numbers
  if (num2 > max) {
    max = num2;
  }
  if (num3 > max) {
    max = num3;
  }
  printf("The maximum of all three numbers is: %d \n", max);
  
  int min = num1; //finding the minimum of three random numbers
  if (num2 < min) {
    min = num2;
  }
  if (num3 < min) {
    min = num3;
  }
  printf("The minimum of all three numbers is: %d \n", min);
  
  printf("I hope you enjoyed these cheerful random numbers!\n");
  
  return 0; //ending the program
}