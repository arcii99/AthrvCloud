//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Load the image data
  FILE *file = fopen("evidence.dat", "r");
  if (!file) {
    perror("Unable to open evidence file");
    exit(1);
  }
  
  // Analyze each image
  unsigned char image[1024];
  while (fread(image, sizeof(unsigned char), 1024, file) == 1024) {
    // Classify the image
    int sum = 0;
    for (int i = 0; i < 1024; i++) {
      sum += image[i];
    }
    int is_clue = (sum > 524288);
    
    // Output the classification
    if (is_clue) {
      printf("This image is a clue!\n");
    } else {
      printf("This image is a distraction.\n");
    }
  }

  // Cleanup
  fclose(file);

  return 0;
}