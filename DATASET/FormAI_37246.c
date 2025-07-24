//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

int search(int array[], int size, int value) {
  int index = -1;
  int i;
  for (i = 0; i < size; i++) {
    if (array[i] == value) {
      index = i;
      break;
    }
  }
  return index;
}

int main() {
  int my_array[] = {2, 6, 8, 29, 59, 83, 90, 101};
  int array_size = sizeof(my_array) / sizeof(my_array[0]);

  printf("Hey, do you want to search for a number in my array? Just tell me!\n");
  printf("Enter the number to search: ");
  int search_number;
  scanf("%d", &search_number);

  int index = search(my_array, array_size, search_number);

  if (index == -1) {
    printf("I'm surprised, but I could not find your number in my array. Maybe it is not there!\n");
  } else {
    printf("Wow! I found your number at index %d in my array. That's impressive!\n", index);
  }

  return 0;
}