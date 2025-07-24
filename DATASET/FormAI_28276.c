//FormAI DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Image Classification System!\n");
  printf("Please enter the file path of the image you want to classify:\n");
  char file_path[100];
  scanf("%s", file_path);
  
  // Image processing code goes here
  // ...
  // ...
  
  printf("The image was classified as: ");
  
  // Randomly choose a label for the image
  int label = rand() % 5;
  switch (label) {
    case 0: printf("Cat\n"); break;
    case 1: printf("Dog\n"); break;
    case 2: printf("Car\n"); break;
    case 3: printf("Tree\n"); break;
    case 4: printf("Building\n"); break;
  }
  
  printf("Thank you for using the Image Classification System!\n");
  return 0;
}