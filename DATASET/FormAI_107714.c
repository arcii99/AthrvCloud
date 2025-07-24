//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int stepCount = 0;
  int calorieCount = 0;
  int pushupCount = 0;

  char name[50];
  char response[50];
  char goal[100] = "To get fit and healthy!";

  printf("Greetings, fair user! I am your Fitness Tracker, your own personal Juliet. What is your name?\n");
  scanf("%s", name);

  printf("Welcome, %s! What is your step count for today?\n", name);
  scanf("%d", &stepCount);
  calorieCount = stepCount * 0.05;
  printf("Excellent! You have burned %d calories today!\n", calorieCount);

  printf("Do you have any fitness goals in mind? If so, what are they?\n");
  getchar();
  fgets(response, 50, stdin);

  printf("Ah, I see. Your goal is %s\n", response);

  printf("As your Fitness Tracker, I would like to recommend that you do some push ups. How many push ups can you do at the moment?\n");
  scanf("%d", &pushupCount);
  printf("Well done, %s! You have completed %d push ups today!\n", name, pushupCount);

  printf("I am proud of your progress, %s! Keep up the good work and you will surely reach your fitness goals.\n", name);

  return 0;
}