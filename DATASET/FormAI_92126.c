//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct movie {
  char title[50];
  char director[50];
  float rating;
};

int main() {
  int num_movies;
  printf("Enter the number of movies: ");
  scanf("%d", &num_movies);

  struct movie *movies = (struct movie*) malloc(num_movies * sizeof(struct movie));
  
  for (int i = 0; i < num_movies; i++) {
    printf("Enter the title of movie %d: ", i+1);
    scanf("%s", &movies[i].title);
    printf("Enter the director of movie %d: ", i+1);
    scanf("%s", &movies[i].director);
    printf("Enter the rating of movie %d (out of 10): ", i+1);
    scanf("%f", &movies[i].rating);
  }

  printf("\nMovie Ratings:\n");
  printf("Title\tDirector\tRating\n");

  float highest_rating = 0;
  char highest_rated_title[50];
  char highest_rated_director[50];

  for (int i = 0; i < num_movies; i++) {
    printf("%s\t%s\t%.1f\n", movies[i].title, movies[i].director, movies[i].rating);
    if (movies[i].rating > highest_rating) {
      highest_rating = movies[i].rating;
      sprintf(highest_rated_title, "%s", movies[i].title);
      sprintf(highest_rated_director, "%s", movies[i].director);
    }
  }

  printf("\nHighest Rated Movie: %s, directed by %s\n", highest_rated_title, highest_rated_director);

  free(movies);
  return 0;
}