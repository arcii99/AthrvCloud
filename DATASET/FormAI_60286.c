//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>

int main() {
  int max_depth = 5; // Set the maximum depth of the fractal
  int step_size = 3; // Set the step size of each drawing step
  int num_branches = 4; // Set the number of branches for each node
  
  void draw_fractal(int depth, int angle, int x, int y) {
    if (depth == max_depth) {
      return;
    }
    
    int i;
    for (i = 0; i < num_branches; i++) {
      int new_x = x + step_size * cos(angle + i * (360 / num_branches));
      int new_y = y + step_size * sin(angle + i * (360 / num_branches));
      draw_fractal(depth + 1, angle + i * (360 / num_branches), new_x, new_y);
    }
  }
  
  // Draw the fractal starting at (0, 0) with an initial angle of 0
  draw_fractal(0, 0, 0, 0);
  
  return 0;
}