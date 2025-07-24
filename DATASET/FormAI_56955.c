//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int sum = 0;
  char input[256];
  
  printf("Enter a string to calculate its checksum: ");
  fgets(input, 256, stdin);

  for (int i = 0; input[i] != '\0'; i++) {
    if (i % 2 == 0) {
      sum += input[i];
    } else {
      sum -= input[i];
    }
  }

  printf("Checksum for %s is %d\n", input, sum);
  
  return 0;
}