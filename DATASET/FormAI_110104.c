//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>

int main() {
  int data[30], checksum = 0, i, j, n;

  printf("Enter the number of data bytes: ");
  scanf("%d", &n);

  printf("Enter the data bytes: ");
  for (i = 0; i < n; ++i) 
    scanf("%d", &data[i]);

  printf("\n\n");

  for (i = 0; i < n; i += 2) {
    checksum += data[i] * 256 + data[i + 1];
    printf("Data word %d: %d * 256 + %d = %d \n", (i / 2) + 1, data[i], data[i + 1], data[i] * 256 + data[i + 1]);
    if (checksum > 0xFFFF) {
      checksum -= 0xFFFF;
      checksum += 1;
    }
  }

  printf("\n\n");

  printf("Checksum: %d", checksum);

  return 0;
}