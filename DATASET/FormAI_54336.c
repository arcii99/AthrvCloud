//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>

int main() {

  int age, height, weight;
  
  printf("Welcome to the Fitness Tracker\n");
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("\nGreat! Now enter your height in centimeters: ");
  scanf("%d", &height);
  
  printf("\nAlmost there! Finally, enter your weight in kilograms: ");
  scanf("%d", &weight);
  
  float bmi = ((float)weight / ((float)height/100 * (float)height/100));
  
  printf("\nYour Body Mass Index (BMI) is %.2f\n", bmi);
  printf("According to the World Health Organization (WHO), your BMI indicates: ");
  
  if (bmi < 18.5) {
    printf("Underweight\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("Normal weight\n");
  } else if (bmi >= 25.0 && bmi <= 29.9) {
    printf("Overweight\n");
  } else {
    printf("Obese\n");
  }
  
  printf("\nThank you for using the Fitness Tracker\n");
  return 0;
}