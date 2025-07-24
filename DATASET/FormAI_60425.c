//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Oh wow, I can't believe it's running!\n");
  
  int *arr = malloc(5 * sizeof(int));
  if(!arr) {
    printf("Oops, couldn't allocate memory.\n");
    exit(1);
  }

  printf("Whoooooooa, I just allocated memory for an array of 5 integers!\n");
  for(int i = 0; i < 5; i++) {
    arr[i] = i + 1;
    printf("Index %d is %d\n", i, arr[i]);
  }

  printf("Let's reallocate the memory for an array of 10 integers now...\n");
  int *new_arr = realloc(arr, 10 * sizeof(int));
  if(!new_arr) {
    printf("Uh oh, couldn't reallocate memory.\n");
    exit(1);
  }

  printf("WOHOOOOOO, I just reallocated memory for an array of 10 integers!!!\n");

  for(int i = 5; i < 10; i++) {
    new_arr[i] = i + 1;
    printf("Index %d is %d\n", i, new_arr[i]);
  }

  printf("Now let's free up that memory...\n");
  free(new_arr);
  
  printf("Oh nooooooo, I think I just leaked memory...\n");
  new_arr = malloc(5 * sizeof(int));
  if(!new_arr) {
    printf("Ah, couldn't allocate memory. Better luck next time...\n");
    exit(1);
  }

  printf("Phew... I just allocated memory for another array of 5 integers.\n");
  
  free(new_arr);
  
  printf("Alright, I think I'm done here. It was really fun playing around with memory management!!\n");

  return 0;
}