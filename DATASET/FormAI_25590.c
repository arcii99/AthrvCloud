//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

/* This program reads in a series of exam scores, calculates the average, 
   and determines the letter grade based on a 10-point scale */

int main() {
  int numScores, score, sum = 0;
  float avg;

  printf("Enter the number of exam scores: ");
  scanf("%d", &numScores);

  for (int i = 1; i <= numScores; i++) {
    printf("Enter exam score %d: ", i);
    scanf("%d", &score);

    sum += score;
  }

  avg = (float)sum / numScores;

  printf("The average is: %.2f\n", avg);

  if (avg >= 9.0) {
    printf("Letter grade: A\n");
  } else if (avg >= 8.0) {
    printf("Letter grade: B\n");
  } else if (avg >= 7.0) {
    printf("Letter grade: C\n");
  } else if (avg >= 6.0) {
    printf("Letter grade: D\n");
  } else {
    printf("Letter grade: F\n");
  }

  return 0;
}