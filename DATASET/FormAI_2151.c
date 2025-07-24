//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the Mind-Bending Movie Rating System!\n\n");
  printf("Please rate your movie on a scale from 1 to 10. But beware, with this rating system, you never know what you'll get.\n");

  scanf("%d", &rating);

  switch(rating) {
    case 1:
      printf("What a trip! This movie will leave you questioning your own existence.");
      break;
    case 2:
      printf("You thought you knew where this movie was going, but think again – the plot twist will blow your mind.");
      break;
    case 3:
      printf("This movie's concept alone will make you question the ethics of humanity.");
      break;
    case 4:
      printf("If you think you understand this movie, you're wrong. Watch it again and pull apart its many, many layers.");
      break;
    case 5:
      printf("This is the kind of movie that sticks with you long after it's finished. A definite must-watch.");
      break;
    case 6:
      printf("Are you even sure this was a movie? You've just experienced something otherworldly.");
      break;
    case 7:
      printf("Mind. Blown. You may never be able to watch a regular movie again after this one.");
      break;
    case 8:
      printf("Buckle up, because this movie is a wild ride from start to finish.");
      break;
    case 9:
      printf("This movie is a masterpiece – every frame feels like a work of art.");
      break;
    case 10:
      printf("Congratulations, you just witnessed perfection. This movie is the reason cinema was invented.");
      break;
    default:
      printf("Hmm, we're not quite sure what to do with this rating. Please enter a number from 1 to 10.");
  }

  printf("\nThank you for using the Mind-Bending Movie Rating System!\n");

  return 0;
}