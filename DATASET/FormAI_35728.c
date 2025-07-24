//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
  char hex[100];
  long decimal, place;
  int i = 0, val, len;

  printf("Greetings, my dear Watson! Today, we shall solve the mystery of converting hexadecimal numbers to decimal.\n");
  printf("Please provide the hexadecimal number: ");
  scanf("%s", hex);

  len = strlen(hex);
  place = 1;
  decimal = 0;

  for (i = 0; hex[i] != '\0'; i++) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      val = hex[i] - 48;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      val = hex[i] - 97 + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      val = hex[i] - 65 + 10;
    } else {
      printf("That is not a valid hexadecimal number!\n");
      return 0;
    }
    decimal += val * place;
    place *= 16;
  }

  printf("The equivalent decimal number is: %ld\n", decimal);
  printf("Thank you for participating. Until our next mystery, my dear Watson!\n");

  return 0;
}