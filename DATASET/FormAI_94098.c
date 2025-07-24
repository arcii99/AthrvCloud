//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include<stdio.h>
#include<stdlib.h>

// A Curious C program to calculate the sum of all even numbers between two given numbers.

int main() {
  int a, b, sum = 0;

  printf("Welcome to the Even Sum Calculator!\n");
  printf("Please enter the first number:\n");
  scanf("%d", &a);

  printf("Great! Now enter the second number:\n");
  scanf("%d", &b);

  if(a > b) {
    int temp = a;
    a = b;
    b = temp;
    printf("\nOops! Looks like you entered the numbers in the wrong order. Don't worry, I've got you covered.\n\n");
  }

  printf("\nAh, I see! You want to find the sum of all even numbers between %d and %d.\n", a, b);

  if(a % 2 == 0) {
    for(int i=a; i<=b; i+=2) {
      sum += i;
    }
  }
  else {
    for(int i=a+1; i<=b; i+=2) {
      sum += i;
    }
  }

  printf("\nDrumroll please...\nThe sum of all even numbers between %d and %d is %d!\n", a, b, sum);

  printf("\nThanks for using the Even Sum Calculator! Have a great day!");

  return 0;
}