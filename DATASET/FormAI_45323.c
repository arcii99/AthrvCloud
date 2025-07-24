//FormAI DATASET v1.0 Category: Funny ; Style: grateful
#include <stdio.h>

int main() {
  printf("I am grateful for the little things in life.\n\n");

  int num = 5;
  int sum = 0;

  printf("Let's take the sum of the first %d numbers.\n", num);
  
  // Loop to find the sum of the first n natural numbers
  for(int i=1; i<=num; i++) {
    sum += i;
    printf("Adding %d to the sum.\n", i);
  }

  printf("The sum of the first %d numbers is: %d.\n\n", num, sum);

  printf("I am also grateful for arrays and loops.\n\n");

  int lucky_numbers[6] = {12, 24, 36, 48, 60, 72};

  printf("Here are my lucky numbers:\n");

  // Loop to print out the lucky numbers
  for(int i=0; i<6; i++) {
    printf("\t%d\n", lucky_numbers[i]);
  }

  printf("\nAnd here are their squares:\n");

  // Loop to find the squares of the lucky numbers
  for(int i=0; i<6; i++) {
    int square = lucky_numbers[i] * lucky_numbers[i];
    printf("\t%d\n", square);
  }

  printf("\nI am grateful for the ability to manipulate strings in C.\n\n");

  char name[20] = "GratitudeBot";
  printf("My name is %s.\n", name);

  // Loop to print out each character of the name
  printf("And here is each character of my name:\n");
  for(int i=0; i<11; i++) {
    printf("\t%c\n", name[i]);
  }

  printf("\nThank you, C programming language, for everything.\n");

  return 0;
}