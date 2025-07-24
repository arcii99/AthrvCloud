//FormAI DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>

// Define a struct for movies
struct Movie {
  char title[100];
  char genre[50];
  int year;
  float rating;
};

int main() {
  int num_movies;
  printf("How many movies would you like to rate? ");
  scanf("%d", &num_movies);

  // Create an array of movies
  struct Movie movies[num_movies];

  // Get information for each movie and calculate average rating
  float total_rating = 0.0;
  for (int i = 0; i < num_movies; i++) {
    printf("\nMovie #%d: \n", i + 1);
    printf("Enter title: ");
    scanf("%s", movies[i].title);
    printf("Enter genre: ");
    scanf("%s", movies[i].genre);
    printf("Enter year: ");
    scanf("%d", &movies[i].year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[i].rating);
    total_rating += movies[i].rating;
  }

  // Calculate average rating
  float avg_rating = total_rating / num_movies;

  // Display results
  printf("\nHere are your movie ratings:\n");
  for (int i = 0; i < num_movies; i++) {
    printf("%d. %s (%s, %d) - %.1f/10\n", i + 1, movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
  }
  printf("\nAverage rating: %.1f/10", avg_rating);

  return 0;
}