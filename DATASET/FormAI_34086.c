//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to my happy data validation program!\n");
  printf("Please enter your age: ");

  int age;
  scanf("%d", &age);

  if (age <= 0 || age > 120) { // validating age
    printf("Oops! Invalid age. Please enter a number between 1 and 120\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
  }

  printf("Great! You are %d years old.\n", age);

  printf("Please enter your weight in kilograms: ");

  float weight;
  scanf("%f", &weight);

  if (weight <= 0 || weight > 200) { // validating weight
    printf("Oh no! Invalid weight. Please enter a number between 1 and 200\n");
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);
  }

  printf("Fantastic! You weigh %.2f kilograms.\n", weight);

  printf("Please enter your salary: ");

  double salary;
  scanf("%lf", &salary);

  if (salary < 0) { // validating salary
    printf("Oops, Invalid salary. Please enter a positive number\n");
    printf("Please enter your salary: ");
    scanf("%lf", &salary);
  }

  printf("Awesome! Your salary is Rs%.2lf per annum.\n", salary);

  printf("Thank you for entering your data!\n");

  return 0;
}