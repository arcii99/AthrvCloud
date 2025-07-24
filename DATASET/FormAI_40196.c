//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex_string[10]; // Initialize hex string
  int num; // Initialize decimal input variable
  printf("Enter a decimal number: ");
  scanf("%d", &num); // Get decimal input from user
  sprintf(hex_string, "%X", num); // Convert decimal to hexadecimal string

  printf("Hexadecimal equivalent: %s\n", hex_string);

  return 0;
}