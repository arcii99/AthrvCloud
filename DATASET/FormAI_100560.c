//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>

int main() {
  // create a smiley face using geometric algorithms
  
  // create the circle for the face
  int radius = 50;
  for(int y = 0; y <= 2 * radius; y++) {
    for(int x = 0; x <= 2 * radius; x++) {
      int dist_x = x - radius;
      int dist_y = y - radius;
      if (dist_x * dist_x + dist_y * dist_y <= radius * radius) {
        printf(":)");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  // create the eyes using triangles
  int eye_size = 10;
  int eye_offset = 20;
  for(int y = eye_offset; y <= eye_offset + eye_size; y++) {
    for(int x = radius - eye_offset; x <= radius - eye_offset + eye_size; x++) {
      if (x >= radius - eye_offset && y <= eye_offset + eye_size - x + radius - eye_offset) {
        printf("o ");
      } else if (x <= radius - eye_offset + eye_size && y <= x - radius + eye_offset + eye_size) {
        printf("o ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // create the mouth using sine function
  int mouth_size = 30;
  int mouth_offset = 30;
  for(int x = 0; x <= 2 * radius; x++) {
    double y = (double) mouth_size / 2 * sin((double) (x - mouth_offset) / radius * 3.14);
    for(int i = 0; i <= mouth_size / 2; i++) {
      if((int) y + radius + i >= radius) {
        printf(":)");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}