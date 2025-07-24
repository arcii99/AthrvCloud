//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

int main() {
  int rating;
  printf("Enter your movie rating (1-10): ");
  scanf("%d", &rating);
  switch(rating) {
    case 1:
    case 2:
    case 3:
      printf("Sorry, this movie is not recommended.\n");
      break;
    case 4:
    case 5:
      printf("This movie is average.\n");
      break;
    case 6:
    case 7:
      printf("This movie is good.\n");
      break;
    case 8:
    case 9:
      printf("This movie is great!\n");
      break;
    case 10:
      printf("This movie is a masterpiece!\n");
      break;
    default:
      printf("Invalid input.\n");
      break;
  }
  return 0;
}