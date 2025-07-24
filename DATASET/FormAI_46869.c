//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decToBin(int decimal_num)
{
  int binary_num_arr[50];
  int i = 0;

  // loop to find binary equivalent of decimal number
  while (decimal_num > 0) {
    // storing remainder in binary array
    binary_num_arr[i] = decimal_num % 2;
    decimal_num = decimal_num / 2;
    i++;
  }

  // looping through binary array to print binary equivalent
  for (int j = i - 1; j >= 0; j--)
    printf("%d", binary_num_arr[j]);
}

// main function
int main()
{
  int decimal_num;

  printf("Enter a decimal number to convert to binary: ");
  scanf("%d", &decimal_num);

  printf("The binary equivalent of %d is: ", decimal_num);
  decToBin(decimal_num);
  
  return 0;
}