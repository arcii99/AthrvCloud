//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FitnessTracker {
  char name[20];
  int age;
  float weight;
  float height;
  float bmi;
} FitnessTracker;

int main () {
  FitnessTracker user;
  printf("Welcome to the Happy Fitness Tracker!\n\n");
  printf("Please enter your name: ");
  scanf("%s", user.name);

  printf("Please enter your age: ");
  scanf("%d", &user.age);

  printf("Please enter your weight in kg: ");
  scanf("%f", &user.weight);

  printf("Please enter your height in meters: ");
  scanf("%f", &user.height);
  
  user.bmi = user.weight / (user.height * user.height);

  printf("\nHello %s, thank you for sharing your information!\n\n", user.name);
  printf("Age: %d\nWeight: %.2f kg\nHeight: %.2f m\nBMI: %.2f\n\n", user.age, user.weight, user.height, user.bmi);

  if (user.bmi < 18.5) {
    printf("You are underweight. Keep eating healthy and exercising regularly!\n");
  } else if (user.bmi >= 18.5 && user.bmi < 25) {
    printf("You are in a healthy weight range. Keep up the good work!\n");
  } else if (user.bmi >= 25 && user.bmi < 30) {
    printf("You are overweight. Try to eat healthy, exercise regularly, and see a doctor for further advice.\n");
  } else {
    printf("You are obese. You should see a doctor and get advice on how to lose weight in a healthy way.\n");
  }

  return 0;
}