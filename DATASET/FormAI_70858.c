//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
  int decimalNum; 
  printf("Enter decimal number: ");
  scanf("%d", &decimalNum);

  int binaryNum[32];
  int i = 0;
  while (decimalNum > 0) {
    binaryNum[i] = decimalNum % 2;
    decimalNum = decimalNum / 2;
    i++;
  }

  printf("Binary conversion is: ");
  for (int j = i - 1; j >= 0; j--) {
      printf("%d", binaryNum[j]);
  }
  return 0;
}