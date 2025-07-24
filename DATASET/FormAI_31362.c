//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>

int main() {
  int num1, num2, num3, num4, checksum;
  
  printf("Enter four integers:\n");
  
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
  
  checksum = (num1 + num2 + num3 + num4) % 16;
  
  printf("Checksum: %d\n", checksum);
  
  return 0;
}