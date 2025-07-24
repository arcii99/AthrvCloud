//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include<stdio.h>
#include<string.h>

void main() {
  char name[20], greeting[] = "Hello, ";
  printf("What's your name? ");
  scanf("%s", name);
  strcat(greeting, name);
  printf("%s!\n\n", greeting);

  printf("Let's learn some C!\n");

  printf("Here's an example of a for loop:\n");
  int i;
  for (i=0; i<10; i++){
    printf("%d ", i);
  }
  printf("\n\n");

  printf("Here's an example of a while loop:\n");
  int j = 0;
  while (j<5){
    printf("C is cool!\n");
    j++;
  }
  printf("\n");

  float num1, num2;
  printf("Enter two numbers: ");
  scanf("%f %f", &num1, &num2);
  printf("The sum of the numbers is %.2f\n\n", num1+num2);

  printf("Thanks for learning C with me!\n");
}