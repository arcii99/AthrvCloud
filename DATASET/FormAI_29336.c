//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>

void binaryConversion(int);

int main() {
  int num;
  printf("Hey there! I'm the Binary Converter Bot\n");
  printf("Give me a number and I'll convert it into binary for you:\n");
  scanf("%d", &num);
  printf("Okay, hold on tight while I get my binary conversion gears moving...\n");
  binaryConversion(num);
  printf("\n\nTa-da! That's your number in binary! Now you can join the Binary Club and speak in 0's and 1's if you want to. Or not... either way, see you later!\n");
  return 0;
}

void binaryConversion(int num) {
  int i, binaryArr[100], binaryLength = 0, isNegative = 0;

  if(num < 0) {
    num = num * -1;
    isNegative = 1;
  }
  
  while(num > 0) {
    binaryArr[binaryLength] = num % 2;
    num = num / 2;
    binaryLength++;
  }

  printf("Here it is: ");

  if(isNegative) {
    printf("-");
  }

  for(i = binaryLength - 1; i >= 0; i--) {
    printf("%d", binaryArr[i]);
  }

  printf("\n");
}