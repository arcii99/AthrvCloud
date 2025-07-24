//FormAI DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Image Classification System!\n\n");
  printf("Please enter the file path of your image:\n");

  char file_path[100];
  scanf("%s", file_path);
  
  printf("\nNow analyzing image...\n");
  printf("Please wait while the AI system determines the content...\n\n");

  // Some fancy algorithm that determines the content of the image
  int content = 2; // Just some made-up value for the sake of the example

  if (content == 0) {
    printf("Congratulations, your image is a picture of a cat.\n");
  }
  else if (content == 1) {
    printf("Congratulations, your image is a picture of a dog.\n");
  }
   else if (content == 2) {
    printf("Uh oh, it looks like your image is not a picture of a cat or a dog.\n");
    printf("Please try again with a different image.\n");
  }

  return 0;
}