//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //Initialize variables
  int movieRating;
  char movieTitle[50];
  
  //Seed random number generator with current time
  srand(time(NULL));
  
  //Ask user for movie title
  printf("Enter the title of the movie: ");
  scanf("%s", movieTitle);
  
  //Generate random movie rating between 1-10
  movieRating = rand() % 10 + 1;
  
  //Print surrealistic movie rating system message
  printf("\n*************************************************\n");
  printf("|\tThe movie \"%s\" has been rated %d/10\t|\n", movieTitle, movieRating);
  printf("|\t   *for entertainment purposes only*   \t|\n");
  printf("|\t   *the rating may or may not be accurate*   \t|\n");
  printf("|\t   *please do not take it seriously*   \t|\n");
  printf("*************************************************\n");
  
  return 0;
}