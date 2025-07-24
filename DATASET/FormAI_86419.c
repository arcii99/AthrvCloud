//FormAI DATASET v1.0 Category: Image Classification system ; Style: surrealist
#include <stdio.h>

int main() {

  // Initialize the variables
  int surrealism = 1;
  char* image;
  int choice;

  // Welcome message
  printf("Welcome to the Surrealist Image Classification System!\n");

  // Prompt the user to input the image
  printf("Please input the image name: ");
  scanf("%s", image);

  // Display the image
  printf("Displaying the image %s...\n", image);

  // Ask the user to choose an option
  printf("Please choose the classification method (1- surrealism): ");
  scanf("%d", &choice);

  // Determine the classification and output the result
  if (choice == surrealism) {
    printf("The image %s is surrealist!\n", image);
  }
  else {
    printf("We're sorry, but we don't have that classification method available at this time.\n");
  }

  return 0;
}