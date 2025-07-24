//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>

int main() {
  int data[100], checksum = 0, c, num_bytes;
  printf("Enter the number of bytes to calculate checksum: ");
  scanf("%d", &num_bytes);

  printf("Enter the data bytes:\n");
  for (c = 0; c < num_bytes; c++) {
    scanf("%d", &data[c]);
    checksum = checksum + data[c];

    if (checksum > 255) {
      checksum = checksum - 255;
    }
  }

  printf("Checksum value: %d\n", 255 - checksum + 1);

  return 0;
}