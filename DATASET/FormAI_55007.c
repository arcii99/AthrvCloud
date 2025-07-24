//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char name[50];
  int age, height, weight;
  float bmi;
  char* status;

  // Ask for user input
  printf("Welcome to the C Fitness Tracker!\n\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("\nPlease enter your age: ");
  scanf("%d", &age);
  printf("\nPlease enter your height (in cm): ");
  scanf("%d", &height);
  printf("\nPlease enter your weight (in kg): ");
  scanf("%d", &weight);

  // Calculate BMI
  bmi = (float)weight / ((float)height / 100 * (float)height / 100);
  printf("\nYour body mass index (BMI) is: %0.2f\n", bmi);

  // Determine status
  if (bmi < 18.5) {
    status = "underweight";
  } else if (bmi >= 18.5 && bmi < 25) {
    status = "normal";
  } else if (bmi >= 25 && bmi < 30) {
    status = "overweight";
  } else {
    status = "obese";
  }

  printf("\nYour BMI status is: %s\n", status);

  // Write to file
  FILE *fp;
  fp = fopen("FitnessTracker.txt", "a");
  fprintf(fp, "%s,%d,%d,%d,%0.2f,%s\n", name, age, height, weight, bmi, status);
  fclose(fp);

  printf("\nThank you for using the C Fitness Tracker!\n");
  return 0;
}