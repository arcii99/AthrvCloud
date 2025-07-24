//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char hexnum[20];
  int decimalnum, i;

  printf("Enter Hexadecimal Value: ");
  scanf("%s", hexnum);

  // Hexadecimal to Decimal Conversion
  decimalnum = 0;
  for(i = 0; hexnum[i] != '\0'; i++) {
    if(hexnum[i] >= '0' && hexnum[i] <= '9') {
      decimalnum = decimalnum * 16 + (hexnum[i] - '0');
    }
    else if(hexnum[i] >= 'A' && hexnum[i] <= 'F') {
      decimalnum = decimalnum * 16 + (hexnum[i] - 'A' + 10);
    }
    else if(hexnum[i] >= 'a' && hexnum[i] <= 'f') {
      decimalnum = decimalnum * 16 + (hexnum[i] - 'a' + 10);
    }
    else {
      printf("Invalid Hexadecimal Number!");
      return 0;
    }
  }

  // Decimal to Binary Conversion
  int binarynum[1000], j = 0;
  int temp = decimalnum;
  while(temp) {
    binarynum[j] = temp % 2;
    temp = temp / 2;
    j++;
  }

  printf("\nDecimal Value: %d\n", decimalnum);
  printf("Binary Value: ");
  for(i = j - 1; i >= 0; i--) {
    printf("%d", binarynum[i]);
  }

  return 0;
}