//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Oh my goodness! I can't believe it!\n");
  printf("I just got memory allocated!\n");
  printf("Let's see how much have I got!\n");

  int *my_memory = malloc(100 * sizeof(int));
  if (my_memory == NULL) {
    printf("Oh no, something went wrong!\n");
    exit(1);
  }

  printf("Woohoo! I got %ld bytes allocated to my_memory!\n", (long int)(100 * sizeof(int)));

  printf("Okay, now let's fill it up with some numbers!\n");
  for (int i = 0; i < 100; i++) {
    my_memory[i] = i * i;
  }

  printf("There, all filled up! Now let's print out what we got:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%-6d", my_memory[i * 10 + j]);
    }
    printf("\n");
  }

  printf("Wow, that was amazing! But now it's time to give it back...\n");
  free(my_memory);
  printf("Goodbye, memory! You were wonderful while you lasted!\n");
  
  return 0;
}