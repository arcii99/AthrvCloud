//FormAI DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
int main() {
  int cat = 7;
  int fish = 15;
  int bird = 3;
  int elephant = 9;
  int spider = 4;
  int rabbit = 6;
  int sum_animals = cat + fish + bird + elephant + spider + rabbit;
  int result = (sum_animals - fish) * elephant / rabbit;
  int counter = 1;
  while (counter <= result) {
    printf("Memory lane is paved with gold\n");
    counter++;
  }
  printf("But why settle for gold, when you can have diamonds?\n");
  int diamond = result * spider - cat % bird;
  printf("You have found %d diamonds in the rough\n", diamond);
  if (diamond > 100) {
    printf("You're rich beyond your wildest dreams!\n");
  } else {
    printf("Keep looking for treasure, you're almost there!\n");
  }
  return 0;
}