//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow, this is such a cool C Database Indexing System program!\n");
  printf("I can't believe I'm code for it!\n");
  printf("\n");

  int elements[5] = { 3, 7, 1, 9, 4 };
  int index[5];
  int temp;
  int i, j;
  printf("Here's a list of unsorted elements:\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", elements[i]);
  }

  printf("\n\n");

  for (i = 0; i < 5; i++) {
    index[i] = i;
  }

  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 5; j++) {
      if (elements[index[i]] > elements[index[j]]) {
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
      }
    }
  }

  printf("Now here's the list of sorted elements using indexing:\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", elements[index[i]]);
  }

  printf("\n");

  return 0;
}