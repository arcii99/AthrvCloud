//FormAI DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to our Image Classification system!\n");

  // Ask user for input image file path
  printf("Please enter the file path for the image you want to classify:\n");
  char file_path[100];
  scanf("%s", file_path);

  // Classify image based on file name
  if (strstr(file_path, "cat") != NULL) {
    printf("This is an image of a cat!\n");
  } else if (strstr(file_path, "dog") != NULL) {
    printf("This is an image of a dog!\n");
  } else {
    printf("Sorry, this image is unclassified.\n");
  }

  // Ask user if they want to classify another image
  printf("Do you want to classify another image? (y/n)\n");
  char response;
  scanf(" %c", &response);
  if (response == 'y' || response == 'Y') {
    main();
  } else {
    printf("Thank you for using our Image Classification system!\n");
  }

  return 0;
}