//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 21;

  while (i--) {
    switch (i % 4) {
      case 0:
        printf("I ");
        break;
      case 1:
        printf("am ");

        if (i == 17)
          goto deep;
        break;
      case 2:
        printf("an ");
        continue;
      case 3:
        printf("avocado");
        break;
    }

    printf("a ");
    continue;

  deep:
    puts("banana");
    printf("and ");
  }

  return EXIT_SUCCESS;
}