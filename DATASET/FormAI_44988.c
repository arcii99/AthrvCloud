//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow, I just created a new compression algorithm!\n");
  printf("This algorithm can compress up to 90%% of the original data.\n");
  printf("Let me show you how it works.\n\n");

  char input[1000], output[1000];
  int count = 1, j = 0;

  printf("Enter the data that you want to compress:\n");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == input[i+1]) {
      count++;
    } 
    else {
      output[j++] = input[i];
      if (count > 1) {
        output[j++] = count+'0';
      }
      count = 1;
    }
  }

  output[j] = '\0';

  printf("\nOriginal data:\n%s\n", input);
  printf("Compressed data:\n%s\n", output);

  printf("\nAmazing, isn't it? With just a few lines of code, I have created a powerful compression algorithm!\n");

  return 0;
}