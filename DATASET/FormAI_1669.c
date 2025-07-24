//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

struct user {
  char name[MAX_NAME_LENGTH];
  float height;
  float weight;
  int age;
};

struct fitness_data {
  float calories_burned;
  float distance_travelled;
  float time_elapsed;
};

void display_user_info(struct user u) {
  printf("Name: %s\n", u.name);
  printf("Age: %d\n", u.age);
  printf("Height: %.2f\n", u.height);
  printf("Weight: %.2f\n", u.weight);
}

void display_fitness_data(struct fitness_data f) {
  printf("Calories burned: %.2f\n", f.calories_burned);
  printf("Distance travelled: %.2f\n", f.distance_travelled);
  printf("Time elapsed: %.2f\n", f.time_elapsed);
}

void update_fitness_data(struct fitness_data *f, float calories, float distance, float time) {
  f->calories_burned += calories;
  f->distance_travelled += distance;
  f->time_elapsed += time;
}

int main() {
  struct user u = {"John", 1.80, 75.0, 30};
  struct fitness_data f = {0.0, 0.0, 0.0};

  printf("Welcome, ");
  display_user_info(u);

  printf("Let's start your workout!\n");

  float calories_per_minute = 10.0;
  float distance_per_minute = 0.2;
  float time_per_set = 5.0;
  int num_sets = 3;

  for (int i = 1; i <= num_sets; i++) {
    printf("Set %d:\n", i);

    float calories = calories_per_minute * time_per_set;
    float distance = distance_per_minute * time_per_set;

    update_fitness_data(&f, calories, distance, time_per_set);

    printf("Calories burned: %.2f\n", calories);
    printf("Distance travelled: %.2f\n", distance);
    printf("Time elapsed: %.2f\n", time_per_set);
  }

  printf("Workout complete! Here are your final stats:\n");
  display_fitness_data(f);

  return 0;
}