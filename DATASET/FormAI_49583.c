//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int* ptr) {
  int i, j;
  for (i = 0; i < 10; i++) {
    printf("[");
    for (j = 0; j < *(ptr+i); j++) {
      printf("#");
    }
    for (j = *(ptr+i); j < 10; j++) {
      printf(" ");
    }
    printf("] %d%%\n", *(ptr+i)*10);
  }
}

int main() {
  int memory[10] = {0};
  int input;
  char choice[5];

  while (1) {
    printf("Enter memory usage as a percentage (0-100): ");
    scanf("%d", &input);
    input = input / 10;

    if (input >= 0 && input <= 10) {
      memory[input]++;
      printf("Memory usage updated.\n");
    } else {
      printf("Invalid input. Please try again.\n");
    }

    display(memory);

    printf("Would you like to quit? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
      break;
    }
  }

  printf("Exiting program...\n");
  return 0;
}