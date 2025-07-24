//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char name[50];
  int age;
  float weight;
  float height;
  int steps_today;
  int calories_burned_today;
};

int main() {
  struct User user1;
  strcpy(user1.name, "John Smith");
  user1.age = 30;
  user1.weight = 75.2;
  user1.height = 1.78;
  user1.steps_today = 5000;
  user1.calories_burned_today = 300;

  printf("********************************************\n");
  printf("******* Welcome to Fitness Tracker! *********\n");
  printf("********************************************\n\n");

  printf("Hello %s, How old are you?\n", user1.name);
  scanf("%d", &user1.age);

  printf("What is your weight in kg?\n");
  scanf("%f", &user1.weight);

  printf("What is your height in meters?\n");
  scanf("%f", &user1.height);

  float bmi = user1.weight/(user1.height*user1.height);
  printf("\nYour BMI is: %.2f\n", bmi);

  printf("\nHow many steps did you take today?\n");
  scanf("%d", &user1.steps_today);

  float calories_per_step = 0.04*user1.weight;
  user1.calories_burned_today = user1.steps_today*calories_per_step;

  printf("\nYou burned %d calories today!\n", user1.calories_burned_today);

  return 0;
}