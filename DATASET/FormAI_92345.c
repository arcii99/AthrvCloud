//FormAI DATASET v1.0 Category: Image Classification system ; Style: genious
// A Genius C Image Classification System Example Program
#include <stdio.h>

// Define Image Struct
typedef struct {
  int width;
  int height;
  char pixels[100][100];
} Image;

// Define Function to Print Image
void print_image(Image img) {
  for (int i = 0; i < img.height; i++) {
    for (int j = 0; j < img.width; j++) {
      printf("%c ", img.pixels[i][j]);
    }
    printf("\n");
  }
}

// Define Function to Classify Images
char classify_image(Image img) {
  int num_black_pixels = 0;
  int total_pixels = img.width * img.height;

  // Loop through all pixels in image
  for (int i = 0; i < img.height; i++) {
    for (int j = 0; j < img.width; j++) {
      if (img.pixels[i][j] == 'X') {
        num_black_pixels++;
      }
    }
  }

  // Calculate Percentage of Black Pixels
  float black_pixel_percentage = (float)num_black_pixels / total_pixels * 100;

  // Classify Image based on Percentage of Black Pixels
  if (black_pixel_percentage >= 50) {
    return 'B'; // Black Image
  } else {
    return 'W'; // White Image
  }
}

int main() {
  // Create Example Images
  Image img1 = { 3, 3, {{'X', '.', 'X'}, {'.', 'X', '.'}, {'X', '.', 'X'}} };
  Image img2 = { 4, 4, {{'X', '.', '.', 'X'}, {'.', 'X', 'X', '.'}, {'.', 'X', 'X', '.'}, {'X', '.', '.', 'X'}} };
  Image img3 = { 4, 4, {{'X', 'X', 'X', 'X'}, {'X', '.', '.', 'X'}, {'X', '.', '.', 'X'}, {'X', 'X', 'X', 'X'}} };

  // Print Example Images
  printf("Image 1:\n");
  print_image(img1);
  printf("\n");

  printf("Image 2:\n");
  print_image(img2);
  printf("\n");

  printf("Image 3:\n");
  print_image(img3);
  printf("\n");

  // Classify Example Images
  char img1_classification = classify_image(img1);
  char img2_classification = classify_image(img2);
  char img3_classification = classify_image(img3);

  // Print Classification Results
  printf("Image 1 is classified as %c\n", img1_classification);
  printf("Image 2 is classified as %c\n", img2_classification);
  printf("Image 3 is classified as %c\n", img3_classification);

  return 0;
}