//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

void raid(int[], int);

int main() {
  int food[5] = {10, 6, 4, 8, 3};
  int survivors = 5;
  int eaten = 0;
  int day = 1;

  while(survivors > 0) {
    printf("Day %d: \n", day++);
    int max = 0;
    int max_index = 0;
    for(int i = 0; i < 5; i++) {
      if(food[i] > max) {
        max = food[i];
        max_index = i;
      }
    }

    if(max > 0) {
      printf("The raiding party found %d cans of food.\n", max);
      food[max_index] = 0;
      raid(food, max);
      eaten += max;
    }

    int deficit = survivors*2 - eaten;
    if(deficit > 0) {
      printf("%d survivors eat %d cans of food.\n", survivors, deficit);
      eaten += deficit;
    }
    else {
      printf("%d cans of food leftover.\n", -1 * deficit);
    }

    for(int i = 0; i < 5; i++) {
      printf("%d cans of food left in barrel %d.\n", food[i], i);
    }

    printf("\n");

    if(eaten >= 10) {
      survivors--;
      printf("A survivor has perished.\n\n");
      eaten -= 10;
    }

    if(survivors == 0) {
      printf("All survivors have perished.\n");
      break;
    }
  }
}

void raid(int food[], int found) {
  int selection = rand() % 2;
  if(selection == 0) {
    int barrel = rand() % 5;
    food[barrel] += found;
    printf("The raiding party added the food to barrel %d.\n\n", barrel);
  }
  else {
    printf("The raiding party destroyed the food.\n\n");
  }
}