//FormAI DATASET v1.0 Category: Scientific ; Style: excited
#include <stdio.h>

int main() {
  printf("Oh my gosh, welcome to my exciting C program!\n");
  printf("Are you ready to learn some awesome science?!\n");
  
  int num1, num2;
  float num3, num4;
  printf("\nLet's start with some basic calculations...\n");
  printf("Enter two integers separated by a space: ");
  scanf("%d %d", &num1, &num2);
  
  int addition = num1 + num2;
  int subtraction = num1 - num2;
  int multiplication = num1 * num2;
  float division = (float)num1 / num2;
  
  printf("\nWow, the sum of your two numbers is %d!\n", addition);
  printf("And if we subtract them, we get %d!\n", subtraction);
  printf("If we multiply them, we get %d!\n", multiplication);
  printf("And finally, if we divide %d by %d, we get %.2f!\n", num1, num2, division);
  
  printf("\nBut that's not all...let's do some more advanced calculations!\n");
  printf("Enter two floating-point numbers separated by a space: ");
  scanf("%f %f", &num3, &num4);
  
  float power = pow(num3, 2);
  float square_root = sqrt(num4);
  float rounded = round(num3);
  
  printf("\nWhoa, if we raise %.2f to the power of 2, we get %.2f!\n", num3, power);
  printf("If we take the square root of %.2f, we get %.2f!\n", num4, square_root);
  printf("Finally, if we round %.2f, we get %.0f!\n", num3, rounded);
  
  printf("\nThat's some pretty cool science, don't you think?\n");
  printf("I hope you enjoyed the program! Have a great day!\n");
  
  return 0;
}