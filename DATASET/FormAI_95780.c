//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>

int main() {
  printf("Welcome to the Surrealist C Color Code Converter!\n");
  printf("Please enter your favorite color in RGB format: ");
  
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  
  printf("Ah, I see! A beautiful blend of %d, %d, and %d.\n", r, g, b);
  printf("Now for the fun part...let's convert to a surreal color code!\n");
  
  int first_digit = r + 4;
  int second_digit = g - 2;
  int third_digit = b * 3;
  
  printf("Your surreal color code is: %d-%d-%d\n", first_digit, second_digit, third_digit);
  printf("Isn't that just dreamy?\n");
  
  return 0;
}