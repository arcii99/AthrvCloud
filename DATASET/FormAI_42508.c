//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please enter your name: ");
  char name[20];
  scanf("%s", name);
  printf("Nice to meet you, %s!\n", name);
  
  printf("What movie did you watch? ");
  char movie[50];
  scanf("%s", movie);

  int rating = 0;
  printf("How would you rate %s on a scale of 1-10? ", movie);
  scanf("%d", &rating);

  if (rating >= 8) {
    printf("Wow! %s is a must-watch movie!\n", movie);
  } else if (rating >= 5 && rating < 8) {
    printf("%s is a decent movie, but could have been better.\n", movie);
  } else {
    // Random funny comment generator
    char* funny_comments[] = {
      "Even a blindfolded monkey could make a better movie.",
      "I'd rather watch paint dry than this movie.",
      "Did the director have their eyes closed the whole time?",
      "I'd give this movie a negative rating if I could.",
      "This movie was a waste of precious hours of my life."
    };
    int index = rand() % 5;
    printf("%s? Really? %s\n", movie, funny_comments[index]);
  }

  printf("Thank you for rating %s, %s. Have a great day!\n", movie, name);
  
  return 0;
}