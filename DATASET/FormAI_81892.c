//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  printf("\nWelcome to The Surrealistic QR Code Generator\n");
  printf("Please enter a string to generate a code: ");

  char string[500];
  scanf("%s", &string);

  int len = strlen(string);

  printf("\n");

  // Generate and Display QR Code
  printf(" ________________\n");
  printf("|                |\n");
  printf("|");

  for(int i = 0; i < len; i++) {
    if(i % 2 == 0) {
      printf("  %c", string[i]);
    } else {
      printf(" [%c]", string[i]);
    }
  }

  printf("  |\n");
  printf("|");

  for(int i = len-1; i >= 0; i--) {
    if(i % 2 == 0) {
      printf(" [%c]", string[i]);
    } else {
      printf("  %c", string[i]);
    }
  }

  printf("  |\n");
  printf("|________________|\n\n");

  printf("Thank you for using The Surrealistic QR Code Generator\n\n");

  return 0;
}