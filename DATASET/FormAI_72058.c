//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include<stdio.h>

int main() {
  printf("O Romeo, Romeo, wherefore art thou Romeo? \n");
  printf("What's in a name? That which we call a rose by any other name would smell as sweet. \n");
  printf("Oh, fair maiden, let me show thee what lies beneath the surface of numbers. \n");
  printf("Enter thy decimal number, and I shall convert it to binary: \n");
  int decimal;
  scanf("%d", &decimal);

  // Conversion process
  int binary[32];
  int i = 0;
  while (decimal > 0) {
    binary[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }

  printf("Behold, fair Juliet, the binary equivalent of thy decimal number: \n");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }

  printf("\n");
  printf("But soft, what light through yonder window breaks? It is the east, and the sun my friend shall rise again upon the morn. \n");
  printf("Farewell, sweet Juliet, until the next time we meet again. \n");
  return 0;
}