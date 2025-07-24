//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

void applygray(int image[IMAGE_WIDTH][IMAGE_HEIGHT]) {
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      int gray = (image[i][j] >> 16) & 0xFF;
      image[i][j] = (gray << 16) | (gray << 8) | gray;
    }
  }
}

void applyblur(int image[IMAGE_WIDTH][IMAGE_HEIGHT]) {
  int temp[IMAGE_WIDTH][IMAGE_HEIGHT];

  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      int count = 0;
      int sum = 0;

      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          int x = i + k;
          int y = j + l;

          if (x >= 0 && x < IMAGE_WIDTH && y >= 0 && y < IMAGE_HEIGHT) {
            count++;
            sum += image[x][y];
          }
        }
      }

      temp[i][j] = sum / count;
    }
  }

  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      image[i][j] = temp[i][j];
    }
  }
}

void applycontrast(int image[IMAGE_WIDTH][IMAGE_HEIGHT], float amount) {
  float factor = (259 * (amount + 255)) / (255 * (259 - amount));

  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      int r = (image[i][j] >> 16) & 0xFF;
      int g = (image[i][j] >> 8) & 0xFF;
      int b = image[i][j] & 0xFF;

      r = (int)(factor * (r - 128) + 128);
      g = (int)(factor * (g - 128) + 128);
      b = (int)(factor * (b - 128) + 128);

      if (r < 0) r = 0;
      if (r > 255) r = 255;
      if (g < 0) g = 0;
      if (g > 255) g = 255;
      if (b < 0) b = 0;
      if (b > 255) b = 255;

      image[i][j] = (r << 16) | (g << 8) | b;
    }
  }
}

void applybrightness(int image[IMAGE_WIDTH][IMAGE_HEIGHT], int amount) {
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      int r = (image[i][j] >> 16) & 0xFF;
      int g = (image[i][j] >> 8) & 0xFF;
      int b = image[i][j] & 0xFF;

      r += amount;
      g += amount;
      b += amount;

      if (r < 0) r = 0;
      if (r > 255) r = 255;
      if (g < 0) g = 0;
      if (g > 255) g = 255;
      if (b < 0) b = 0;
      if (b > 255) b = 255;

      image[i][j] = (r << 16) | (g << 8) | b;
    }
  }
}

void applyrotate(int image[IMAGE_WIDTH][IMAGE_HEIGHT], float angle) {
  int cx = IMAGE_WIDTH / 2;
  int cy = IMAGE_HEIGHT / 2;

  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      float x = (i - cx) * cos(angle) - (j - cy) * sin(angle) + cx;
      float y = (i - cx) * sin(angle) + (j - cy) * cos(angle) + cy;

      int x1 = (int)x;
      int y1 = (int)y;

      int x2 = x1 + 1;
      int y2 = y1 + 1;

      if (x1 < 0 || x2 >= IMAGE_WIDTH || y1 < 0 || y2 >= IMAGE_HEIGHT) {
        continue;
      }

      int q11 = image[x1][y1];
      int q21 = image[x2][y1];
      int q12 = image[x1][y2];
      int q22 = image[x2][y2];

      float fx = x - x1;
      float fy = y - y1;

      float r1 = q11 * (1 - fx) + q21 * fx;
      float r2 = q12 * (1 - fx) + q22 * fx;
      float r = r1 * (1 - fy) + r2 * fy;

      image[i][j] = (int)r;
    }
  }
}

int main() {
  int image[IMAGE_WIDTH][IMAGE_HEIGHT];

  // Initialize image with random grayscale values
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      int gray = rand() % 256;
      image[i][j] = (gray << 16) | (gray << 8) | gray;
    }
  }

  // Apply transformations
  applygray(image);
  applyblur(image);
  applycontrast(image, 50.0f);
  applybrightness(image, 50);
  applyrotate(image, M_PI_2);

  // Save image to file
  FILE *outfile = fopen("output.pgm", "wb");
  fprintf(outfile, "P6\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      unsigned char r = (image[i][j] >> 16) & 0xFF;
      unsigned char g = (image[i][j] >> 8) & 0xFF;
      unsigned char b = image[i][j] & 0xFF;
      fwrite(&r, sizeof(unsigned char), 1, outfile);
      fwrite(&g, sizeof(unsigned char), 1, outfile);
      fwrite(&b, sizeof(unsigned char), 1, outfile);
    }
  }
  fclose(outfile);

  return 0;
}