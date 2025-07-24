//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>

int main() {
  int numFoodOptions = 7;
  char* foodOptions[] = {"Burgers", "Tacos", "Pizza", "Sushi", "Fries", "Ice Cream", "Smoothies"};

  printf("Welcome to the food court!\n\n");

  for (int i = 0; i < numFoodOptions; i++) {
    printf("%d. %s\n", i+1, foodOptions[i]);
  }

  printf("\nNow let's create a graph representation of the food court.\n\n");

  printf("   |     |\n");
  printf(" %s --- %s\n", foodOptions[0], foodOptions[1]);
  printf(" |  \\ /  |\n");
  printf(" |  %s  |\n", foodOptions[4]);
  printf(" |  / \\  |\n");
  printf(" %s --- %s\n", foodOptions[3], foodOptions[2]);
  printf("   |     |\n");

  printf("\nThis graph represents the different types of food options and their connections in the food court.\n");
  printf("You can start with any food option and follow the edges to try all the delicious food available!\n");

  return 0;
}