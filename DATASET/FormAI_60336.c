//FormAI DATASET v1.0 Category: Random ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  
  printf("Welcome to the Happy Random Numbers Generator!\n");
  printf("Let's generate some numbers to make your day!\n");
  
  //Get user input on how many numbers they want to generate
  int num;
  printf("Enter how many random numbers do you want to generate? ");
  scanf("%d", &num);
  printf("\n");
  
  //Seed the random number generator with the current time
  srand(time(0));
  
  //Generate and print out the random numbers
  for(int i=0; i<num; i++) {
    int rand_num = rand() % 100 + 1;
    printf("Here's a happy random number: %d\n", rand_num);
  }
  
  printf("\nHope these numbers brought a smile to your face!\n");
  printf("Have a great day!\n");
  
  return 0;
}