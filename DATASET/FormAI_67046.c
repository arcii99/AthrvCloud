//FormAI DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Robot Movement Control Program\n\n");

  int direction;
  int distance;

  // Robot movement options
  printf("1. Forward\n");
  printf("2. Backward\n");
  printf("3. Left\n");
  printf("4. Right\n\n");

  // Prompt user for input
  printf("Enter direction (1-4): ");
  scanf("%d", &direction);

  if(direction < 1 || direction > 4) {
    printf("\nInvalid direction!\n");
    exit(0);
  }

  printf("Enter distance: ");
  scanf("%d", &distance);

  // Robot movement output
  switch (direction) {
    case 1:
      printf("\nMoved forward by %d units.\n", distance);
      break;
    case 2:
      printf("\nMoved backward by %d units.\n", distance);
      break;
    case 3:
      printf("\nMoved left by %d units.\n", distance);
      break;
    case 4:
      printf("\nMoved right by %d units.\n", distance);
      break;
  }
  
  return 0;
}