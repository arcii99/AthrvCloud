//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the Puzzling Movie Rating System\n");
  printf("Please rate the movie you just watched on a scale of 1 to 10\n");
  scanf("%d", &rating);

  if (rating == 1) {
    printf("You seem to hate puzzles! Please try a different genre!\n");
  }
  else if (rating >= 2 && rating <= 4) {
    printf("You need to work on your puzzling skills! Give the movie another try.\n");
  }
  else if (rating >= 5 && rating <= 7) {
    printf("You're getting better at this! Keep puzzling.\n");
  }
  else if (rating >= 8 && rating <= 9) {
    printf("You're a natural puzzler! Keep up the good work and challenge yourself with harder puzzles.\n");
  }
  else if (rating == 10) {
    printf("You're a puzzle master! Congratulations and keep pushing yourself to the limits.\n");
  }
  else {
    printf("Invalid rating entered. Please try again.\n");
  }

  return 0;
}