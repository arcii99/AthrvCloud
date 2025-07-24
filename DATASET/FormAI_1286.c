//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>

int main() {
  int choice;

  printf("Enter a number between 1 and 5 to control the robot's movement: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("The robot transforms into a snake and slithers across the ground.\n");
      break;
    case 2:
      printf("The robot transforms into a spider and crawls up the wall.\n");
      break;
    case 3:
      printf("The robot transforms into a bird and flies through the air.\n");
      break;
    case 4:
      printf("The robot transforms into a shark and swims through the water.\n");
      break;
    case 5:
      printf("The robot transforms into a cheetah and runs at superhuman speed.\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}