//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>

int main() {
  FILE *fp;
  unsigned char img[64][64];  // 64x64 image
  
  // Open image file
  fp = fopen("image.bin", "rb");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  
  // Read image data into array
  fread(img, sizeof(unsigned char), 64*64, fp);
  
  // Let's say we want to apply a filter to the image
  int filter[3][3] = {
    {-1, -1, -1},
    {-1,  9, -1},
    {-1, -1, -1}
  };
  
  // Apply the filter to each pixel
  int i, j, x, y;
  unsigned char new_img[64][64];
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
      int sum = 0;
      for (x = -1; x <= 1; x++) {
        for (y = -1; y <= 1; y++) {
          // Check boundaries
          if (i+x >= 0 && i+x < 64 && j+y >= 0 && j+y < 64) {
            sum += img[i+x][j+y] * filter[x+1][y+1];
          }
        }
      }
      new_img[i][j] = (sum < 0) ? 0 : ((sum > 255) ? 255 : sum);
    }
  }
  
  // Save new image to file
  fp = fopen("new_image.bin", "wb");
  if (fp == NULL) {
    printf("Error creating file.\n");
    return 1;
  }
  fwrite(new_img, sizeof(unsigned char), 64*64, fp);
  
  printf("Image processed successfully.\n");
  return 0;
}