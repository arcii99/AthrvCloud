//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

void generate_cantor_set(int depth, double left, double right) {
  if (depth == 0) {
    return;
  }
  double interval_size = (right - left) / 3;
  double left_third = left + interval_size;
  double right_third = right - interval_size;
 
  printf("[%f, %f]\n", left, right);
 
  generate_cantor_set(depth - 1, left, left_third);
  generate_cantor_set(depth - 1, right_third, right);
}

int main() {
  int depth;
  printf("Enter the depth of the Cantor Set: ");
  scanf("%d", &depth);
  generate_cantor_set(depth, 0.0, 1.0);
  return 0;
}