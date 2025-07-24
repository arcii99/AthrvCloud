//FormAI DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>

int main() {
  int rating;
  char movieTitle[50];
  printf("Welcome to the Brave Movie Rating System.\n");
  printf("Please enter the title of the movie: ");
  scanf("%[^\n]s", movieTitle);
  printf("Please rate the movie out of 10: ");
  scanf("%d", &rating);
  if (rating > 0 && rating <= 10) {
    printf("Thank you for rating %s a %d out of 10.\n", movieTitle, rating);
    if (rating == 10) {
      printf("Well done! %s is a masterpiece!\n", movieTitle);
    } else if (rating >= 7) {
      printf("%s is a great movie!\n", movieTitle);
    } else if (rating >= 4) {
      printf("%s is an average movie.\n", movieTitle);
    } else {
      printf("%s is a terrible movie.\n", movieTitle);
    }
  } else {
    printf("Invalid rating.\n");
  }
  return 0;
}