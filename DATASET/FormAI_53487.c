//FormAI DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>

/* This program demonstrates the use of functions and arrays to keep track of a student's grades */

// function declaration
float calculateAverage(int grades[], int size);

int main() {
  // declare variables
  int numberOfGrades;
  int grades[20];
  float average;

  // get number of grades from user
  printf("Enter the number of grades: ");
  scanf("%d", &numberOfGrades);

  // get grades from user
  printf("Enter %d grades: ", numberOfGrades);
  for (int i = 0; i < numberOfGrades; i++) {
    scanf("%d", &grades[i]);
  }

  // calculate average and print results
  average = calculateAverage(grades, numberOfGrades);
  printf("The average grade is %.2f", average);

  return 0;
}

// function definition
float calculateAverage(int grades[], int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += grades[i];
  }
  return sum / size;
}