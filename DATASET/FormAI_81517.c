//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
/* Cryptic C Hexadecimal Converter */

#include <stdio.h>

int main() {
  printf("Enter a number in hexadecimal format: ");
  char input[50], output[50];
  scanf("%s", input);
  
  char *p = input;
  int i = 0;
  while (*p) {
    int val;
    switch (*p) {
      case '0': val = 0; break;
      case '1': val = 1; break;
      case '2': val = 2; break;
      case '3': val = 3; break;
      case '4': val = 4; break;
      case '5': val = 5; break;
      case '6': val = 6; break;
      case '7': val = 7; break;
      case '8': val = 8; break;
      case '9': val = 9; break;
      case 'A': val = 10; break;
      case 'B': val = 11; break;
      case 'C': val = 12; break;
      case 'D': val = 13; break;
      case 'E': val = 14; break;
      case 'F': val = 15; break;
      default: printf("Invalid input"); return 1;
    }
    output[i] = val;
    p++;
    i++;
  }
  
  printf("The number in decimal format is: ");
  for (int j = 0; j < i; j++) {
    printf("%d", output[j]);
  }
  
  return 0;
}