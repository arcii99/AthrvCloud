//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* This program will take in various grades for a student and calculate their final grade. */

int main() {
  float hw_grade, quiz_grade, test_grade, final_grade;

  // Take input for homework grade
  printf("Enter homework grade (0-100): ");
  scanf("%f", &hw_grade);
  if (hw_grade < 0 || hw_grade > 100) {
    printf("Invalid input, please provide a grade between 0 and 100\n");
    exit(1);
  }

  // Take input for quiz grade
  printf("Enter quiz grade (0-100): ");
  scanf("%f", &quiz_grade);
  if (quiz_grade < 0 || quiz_grade > 100) {
    printf("Invalid input, please provide a grade between 0 and 100\n");
    exit(1);
  }

  // Take input for test grade
  printf("Enter test grade (0-100): ");
  scanf("%f", &test_grade);
  if (test_grade < 0 || test_grade > 100) {
    printf("Invalid input, please provide a grade between 0 and 100\n");
    exit(1);
  }

  // Calculate final grade
  final_grade = (hw_grade * 0.25) + (quiz_grade * 0.25) + (test_grade * 0.5);

  // Output final grade
  printf("Final grade: %.2f\n", final_grade);

  return 0;
}