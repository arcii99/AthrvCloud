//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void travel(int distance); // declaring the function

// main function
int main() {
  int distance;
  printf("Welcome to the Interstellar Space Adventure!\n");
  printf("How far would you like to travel? Enter distance in light years: ");
  scanf("%d", &distance); // reading input from user

  travel(distance); // calling the function
  printf("\nCongratulations, you have completed your journey!\nEnjoy your stay in the new galaxy!\n");

  return 0;
}

// function definition
void travel(int distance) {
  int i;
  printf("\n\nStarting your journey...\n\n");

  for(i = 1; i <= distance; i++) {
    printf("Light year %d: Travelling...\n", i);
    if(i%10 == 0) {
      printf("Collecting resources...\n"); // collecting resources every 10 light years
    }
  }
  printf("\n\nYou have arrived in a new galaxy!\n\n");
}