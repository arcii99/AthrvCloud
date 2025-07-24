//FormAI DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>

int main() {
  float image[3][4] = {{0.3, 0.4, 0.2, 0.1},
                       {0.1, 0.5, 0.1, 0.3},
                       {0.8, 0.1, 0.05, 0.05}};
  float weights[4][2] = {{0.1, 0.5},
                         {0.2, 0.4},
                         {0.3, 0.3},
                         {0.4, 0.2}};
  float bias[2] = {0.1, 0.2};
  float output[3][2] = {{0}, {0}, {0}};
  
  // Perform matrix multiplication and summation
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 4; k++) {
        output[i][j] += image[i][k] * weights[k][j];
      }
      output[i][j] += bias[j];
    }
  }

  // Print the output
  printf("Image classification results:\n");
  for (int i = 0; i < 3; i++) {
    printf("%f, %f\n", output[i][0], output[i][1]);
  }
    
  return 0;
}