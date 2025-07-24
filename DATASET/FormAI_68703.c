//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int i, j, k;
  
  printf("Welcome to the post-apocalyptic DSP program.\n");
  printf("Please enter 3 integers to perform convolution with:\n");
  scanf("%d %d %d", &i, &j, &k);
  
  int signal[10] = {1, 3, 2, 1, 4, 5, 2, 6, 7, 3};
  int filter[3] = {i, j, k};
  int output[10];
  
  printf("\nSignal:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", signal[i]);
  }
  printf("\n\nFilter:\n");
  for (i = 0; i < 3; i++) {
    printf("%d ", filter[i]);
  }
  
  for (i = 0; i < 10; i++) {
    output[i] = 0;
    for (j = 0; j < 3; j++) {
      if (i - j >= 0 && i - j < 10) {
        output[i] += signal[i - j] * filter[j];
      }
    }
  }
  
  printf("\n\nOutput:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", output[i]);
  }
  
  printf("\n\nProgram terminated. Stay safe in this post-apocalyptic world.\n");
  return 0;
}