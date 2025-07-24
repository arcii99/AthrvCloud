//FormAI DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the function for our classifier
int classify_image(char* image_path)
{
  // Some fancy machine learning algorithm here...
  int result = rand() % 2;
  
  return result;
}

int main()
{
  // Welcome message
  printf("Welcome to the Image Classification System!\n");
  
  // Prompt the user for image path
  printf("Please enter the path to your image file: ");
  
  // Get the user input
  char image_path[100];
  scanf("%s", image_path);
  
  // Classify the image
  int classification = classify_image(image_path);
  
  // Print the classification result
  if (classification == 0)
  {
    printf("Congratulations! Your image is a cat!\n");
  }
  else
  {
    printf("Uh oh, looks like your image is not a cat :(\n");
  }
  
  // Exit message
  printf("Thank you for using our Image Classification System!\n");
  
  return 0;
}