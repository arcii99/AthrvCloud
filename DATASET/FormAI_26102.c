//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the C Movie Rating System\n");
  printf("What rating would you like to give the movie? (1-5): ");
  scanf("%d", &rating);
 
  switch(rating) {
    case 1:
      printf("Sorry, we cannot accept a rating lower than 2.\n");
      break;
    case 2:
      printf("Thank you for your rating.\n");
      break;
    case 3:
      printf("Thanks for rating us. We will do better.\n");
      break;
    case 4:
      printf("Wow thanks for the awesome rating!\n");
      break;
    case 5:
      printf("You must have loved our movie. Thanks for the 5 stars!\n");
      break;
    default:
      printf("Invalid rating input. Please enter a number between 1 and 5.\n");
      break;
  }
  return 0;
}