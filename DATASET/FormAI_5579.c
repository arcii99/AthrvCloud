//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to our Happy City Finder program!\n");

  // Create arrays to store city names and happiness scores
  char cities[5][20] = {"Helsinki", "Copenhagen", "Tokyo", "Stockholm", "Oslo"};
  int happiness_scores[5] = {85, 90, 75, 80, 88};

  // Loop through arrays to find highest happiness score
  int max_score = happiness_scores[0];
  int max_index = 0;
  for (int i = 1; i < 5; i++) {
    if (happiness_scores[i] > max_score) {
      max_score = happiness_scores[i];
      max_index = i;
    }
  }

  // Print out the happiest city and its score
  printf("The happiest city is %s with a happiness score of %d.\n", cities[max_index], max_score);

  return 0;
}