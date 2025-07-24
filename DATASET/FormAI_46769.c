//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hey there, let's play a game!\n");
  printf("I'll give you a list of coordinates and you have to tell me the area of the polygon they form!\n");
  
  // Let's define the polygon coordinates
  int polygon[4][2] = {{0, 0}, {0, 5}, {5, 5}, {3, 2}};
  
  // Let's calculate the area using the Shoelace Formula
  double area = 0.0;
  for (int i = 0; i < 3; ++i) {
    area += (polygon[i][0] * polygon[i+1][1] - polygon[i+1][0] * polygon[i][1]);
  }
  area += (polygon[3][0] * polygon[0][1] - polygon[0][0] * polygon[3][1]);
  area /= 2.0;
  
  printf("The area of the polygon is: %lf\n", area);
  
  return 0;
}