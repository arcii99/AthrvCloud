//FormAI DATASET v1.0 Category: Image compression ; Style: funny
#include <stdio.h>

#define COMPRESSED_IMAGE_SIZE 256 // We're compressing to a 256-bit image

char compressed_image[COMPRESSED_IMAGE_SIZE]; // Store our compressed image here

// Compress the image
void compress_image(char* image, int image_size) {

  printf("Squishing those pixels...\n");

  // Loop through the image and compress each pixel
  for (int i = 0; i < image_size; i++) {

    int compressed_pixel = image[i] / 2; // This is how we compress our pixel

    compressed_image[i] = compressed_pixel; // Store the compressed pixel in our array

    // Let's have some fun with our compression process
    if (compressed_pixel >= 100) {
      printf("Wow, we really squished that pixel! It went from %d to %d!\n", image[i], compressed_pixel);
    } else if (compressed_pixel >= 50) {
      printf("This is like those events where people squeeze into tiny cars. We squeezed this pixel from %d to %d!\n", image[i], compressed_pixel);
    } else {
      printf("A little compression never hurt nobody. This pixel went from %d to %d.\n", image[i], compressed_pixel);
    }

  }

}

int main() {

  char image[] = { 255, 250, 200, 150, 100, 50, 25, 0 }; // Our uncompressed image

  int image_size = sizeof(image) / sizeof(char); // Calculate the size of our image array

  compress_image(image, image_size); // Compress the image

  printf("The compressed image looks like this:\n");

  // Print out our compressed image
  for (int i = 0; i < image_size; i++) {
    printf("%d ", compressed_image[i]);
  }

  printf("\n");

  return 0;
}