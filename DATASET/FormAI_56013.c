//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>

int main() {
  // Open the image file
  FILE *image_file = fopen("image.jpg", "rb");
  
  // Read the image header
  char header[54];
  fread(header, sizeof(char), 54, image_file);
  
  // Calculate the image size
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];
  int bits_per_pixel = *(short*)&header[28];
  int image_size = width * height * (bits_per_pixel / 8);
  
  // Read the image data
  unsigned char *image_data = (unsigned char*) malloc(image_size);
  fread(image_data, sizeof(char), image_size, image_file);
  
  // Close the image file
  fclose(image_file);
  
  // Determine the colors of the image
  int num_colors = 0;
  for (int i = 0; i < image_size; i += 3) {
    unsigned char r = image_data[i];
    unsigned char g = image_data[i+1];
    unsigned char b = image_data[i+2];
    if (r == g && g == b) {
      num_colors++;
    }
  }
  
  // Determine the image type
  if (num_colors == 0) {
    printf("This is a black and white image.\n");
  } else if (num_colors == 1) {
    printf("This is a grayscale image.\n");
  } else {
    printf("This is a color image.\n");
  }
  
  return 0;
}