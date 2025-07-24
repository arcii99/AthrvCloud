//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>

int main() {
  int rating;
  char movie_title[50];

  printf("Enter movie title: ");
  scanf("%s", movie_title);

  printf("Rate the movie from 1-10: ");
  scanf("%d", &rating);

  printf("\n\nYou rated %s a %d out of 10.\n\n", movie_title, rating);

  if (rating >= 8) {
    printf("Excellent! This movie is a must-see!\n");
  } else if (rating >= 6 && rating < 8) {
    printf("Pretty good! You'll definitely enjoy it.\n");
  } else if (rating >= 4 && rating < 6) {
    printf("Meh. It's not terrible, but you probably won't love it.\n");
  } else if (rating > 0 && rating < 4) {
    printf("Yikes. This one's a stinker.\n");
  } else {
    printf("Invalid rating. Please enter a number between 1 and 10.\n");
  }

  return 0;
}