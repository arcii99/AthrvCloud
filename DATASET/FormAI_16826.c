//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Welcome to the C Color Code Converter!\n");

  char hex[8];
  printf("Please enter a 6 digit hexadecimal color code: ");
  fgets(hex, sizeof(hex), stdin); // read input from user

  // validate input
  int i, valid = 1;
  for(i = 0; i < 6; i++) {
    if(!isdigit(hex[i]) && (hex[i] < 'A' || hex[i] > 'F') && (hex[i] < 'a' || hex[i] > 'f')) {
      valid = 0;
      break;
    }
  }

  if(!valid) {
    printf("Invalid input! Please enter a 6 digit hexadecimal color code.\n");
    return 1;
  }

  // convert hexadecimal to decimal
  unsigned int decimal = (unsigned int) strtol(hex, NULL, 16);

  // extract red, green, blue components
  int red = decimal >> 16;
  int green = (decimal & 0x00FF00) >> 8;
  int blue = decimal & 0x0000FF;

  // display results
  printf("The decimal color code is: %u\n", decimal);
  printf("The RGB color code is: (%d, %d, %d)\n", red, green, blue);

  // convert decimal to hexadecimal
  char hex2[8];
  sprintf(hex2, "%06X", decimal);

  printf("The hexadecimal color code is: #%s\n", hex2);

  return 0;
}