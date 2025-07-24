//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[30];
  int age, lucky_number, random_number;
  int sum = 0, i;
  printf("Welcome to the Automated Fortune Teller\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  // Sum the digits of the age
  while (age != 0) {
    sum += age % 10;
    age /= 10;
  }
  
  printf("Please enter your lucky number: ");
  scanf("%d", &lucky_number);
  // Generate a random number
  srand(time(NULL));
  random_number = rand() % 100 + 1;
  
  // Calculate the fortune
  int fortune = (sum * lucky_number) % random_number;
  printf("Welcome %s, your fortune today is: ", name);
  switch (fortune) {
    case 0:
      printf("You will be rich and famous!\n");
      break;
    case 1:
      printf("Love is in your future!\n");
      break;
    case 2:
      printf("You will have a long and healthy life!\n");
      break;
    case 3:
      printf("You will travel to exotic places!\n");
      break;
    case 4:
      printf("You will meet your soulmate!\n");
      break;
    case 5:
      printf("You will achieve great success in your career!\n");
      break;
    default:
      printf("You will find happiness in unexpected ways!\n");
      break;
  }

  return 0;
}