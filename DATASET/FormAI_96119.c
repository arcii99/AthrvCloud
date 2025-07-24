//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the unique C Movie Rating System!\n");
  printf("Please rate the last movie you watched from 1 to 10: ");
  scanf("%d", &rating);

  switch(rating) {
    case 1:
      printf("Wow, you really hated that movie!\n");
      break;
    case 2:
      printf("That movie must have been pretty bad.\n");
      break;
    case 3:
      printf("Not a great movie, huh?\n");
      break;
    case 4:
      printf("You didn't find that movie very entertaining, did you?\n");
      break;
    case 5:
      printf("A mediocre movie, it seems.\n");
      break;
    case 6:
      printf("So that movie was just okay?\n");
      break;
    case 7:
      printf("Glad to hear you enjoyed it!\n");
      break;
    case 8:
      printf("An above average movie it seems.\n");
      break;
    case 9:
      printf("Wow! You really loved that movie!\n");
      break;
    case 10:
      printf("You ranked it a perfect score! That movie must have been amazing.\n");
      break;
    default:
      printf("Hmmm, that rating doesn't seem right. Please enter a number from 1 to 10.\n");
      break;
  }

  return 0;
}