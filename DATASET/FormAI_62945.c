//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>

// function declaration
void dec_to_hex(int decimal_num);

int main() {
  int decimal_num;

  printf("Welcome to the Decimal to Hexadecimal Converter!\n");
  printf("Please enter a decimal number: ");
  scanf("%d", &decimal_num);

  // calling the conversion function
  dec_to_hex(decimal_num);

  printf("\nThank you for using our converter!\n");

  return 0;
}

// function definition
void dec_to_hex(int decimal_num) {
  int rem, i=1, j, temp;
  char hexadecimal_num[100];

  temp = decimal_num;

  // conversion to hexadecimal
  while(temp != 0) {
    rem = temp % 16;

    if(rem < 10)
      rem = rem + 48;
    else
      rem = rem + 55;

    hexadecimal_num[i++] = rem;
    temp = temp / 16;
  }

  // printing the result in reverse order
  printf("\nThe hexadecimal representation of %d is: ", decimal_num);
  for(j=i-1; j>0; j--)
    printf("%c", hexadecimal_num[j]);
}