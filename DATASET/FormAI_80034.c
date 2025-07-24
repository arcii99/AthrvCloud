//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main(void) {
  int rating;

  printf("Welcome to the Comedy Movie Rating System!\n");
  printf("Please rate the movie you just saw on a scale of 1 to 10: ");
  scanf("%d", &rating);

  if (rating < 1) {
    printf("Dude, did you even watch the movie?\n");
  } else if (rating >= 1 && rating <= 3) {
    printf("Wow, that movie was worse than a knock-knock joke!\n");
  } else if (rating >= 4 && rating <= 6) {
    printf("Eh, that movie had a few chuckles but overall it was meh.\n");
  } else if (rating >= 7 && rating <= 9) {
    printf("Ha! That movie was pretty funny, I'll give it a thumbs up!\n");
  } else {
    printf("That movie was hilarious, I laughed so hard I almost wet myself!\n");
  }

  return 0;
}