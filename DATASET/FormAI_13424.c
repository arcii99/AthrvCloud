//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include<stdio.h>

int main(void) {
  // Let's declare some variables
  int age=0;
  char name[30];
  float height = 0.0; 
  double weight = 0.0;

  // Let's ask the user for their information
  printf("Hey there! What's your name?\n");
  scanf("%s", &name);
  printf("Nice to meet you, %s! How old are you?\n", name);
  scanf("%d", &age);
  printf("Cool! And how tall are you in meters?\n");
  scanf("%f", &height);
  printf("Awesome, %s! And what about your weight in kg?\n", name);
  scanf("%lf", &weight);

  // Let's output the collected information
  printf("So your name is %s, you are %d years old and you are %.2f meters tall.\n", name, age, height);
  printf("Also, you weigh %.2lf kg! That's amazing %s!\n", weight, name);

  // And finally, let's check if the person is of legal age
  if(age >= 18) {
    printf("%s, you are officially an adult!\n", name);
  } else {
    printf("%s, you are still a minor... don't worry, you'll get there soon!\n", name);
  }

  return 0;
}