//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: romantic
// My Heart is a Geometric Algorithm

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
  double radius = 10.0;
  double centerX = 0.0;
  double centerY = 0.0;
  double theta = 0.0;
  
  while (1) {
    printf("My heart beats for you...\n");
    // Heart shape equation with polar coordinates
    double x = radius * 16.0 * pow(sin(theta), 3.0);
    double y = -radius * (13.0 * cos(theta) - 5.0 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta));    

    for (int i = -30; i < 30; i++) {
      for (int j = -30; j < 30; j++) {
        double distance = sqrt(pow(i - centerX, 2) + pow(j - centerY, 2));
        if (distance <= radius) {
          printf("\u2665"); // Heart symbol
        } else {
          printf(" ");
        } 
      }
      printf("\n");
    }

    theta += PI / 20.0; // Rotate heart shape
    if (theta >= 2 * PI) {
      theta = 0.0;
    }
  }
  
  return 0;
}