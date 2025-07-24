//FormAI DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>

// This is a unique rating system to rate movies based on the director, cast, plot, soundtrack, and overall enjoyment.
// The range of the rating will be from 0 to 100.

int main() {
  // Prompt the user for the movie details
  printf("Please rate the following aspects of the movie on a scale of 1 to 10: \n");
  
  int director_rating, cast_rating, plot_rating, soundtrack_rating, enjoyment_rating;
  printf("Director: ");
  scanf("%d", &director_rating);
  printf("Cast: ");
  scanf("%d", &cast_rating);
  printf("Plot: ");
  scanf("%d", &plot_rating);
  printf("Soundtrack: ");
  scanf("%d", &soundtrack_rating);
  printf("Enjoyment: ");
  scanf("%d", &enjoyment_rating);

  // Calculate the overall rating
  double overall_rating = (director_rating + cast_rating + plot_rating + soundtrack_rating + enjoyment_rating) / 5.0;
  int final_rating = (int)(overall_rating * 10);

  // Display the final rating
  if (final_rating >= 90) {
    printf("Congratulations! This movie deserves an A rating. Its overall rating is %d\n", final_rating);
  } else if (final_rating >= 80) {
    printf("This movie deserves a B rating. Its overall rating is %d\n", final_rating);
  } else if (final_rating >= 70) {
    printf("This movie deserves a C rating. Its overall rating is %d\n", final_rating);
  } else if (final_rating >= 60) {
    printf("This movie deserves a D rating. Its overall rating is %d\n", final_rating);
  } else {
    printf("Unfortunately, this movie deserves an F rating. Its overall rating is %d\n", final_rating);
  }

  return 0;
}