//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {
  int x, y, z;
  printf("\n\nHowdy there! I'm a chatbot, and I'm here to solve some arithmetic problems! Let's do this!\n\n");

  printf("Enter the first number: ");
  scanf("%d", &x);

  printf("Enter the second number: ");
  scanf("%d", &y);

  printf("Enter the third number: ");
  scanf("%d", &z);

  int sum = x + y +z;
  int product = x * y * z;
  int difference = x - y - z;
  float average = (float)sum/3; // To get a decimal value, type casting is used here.
  int max = (x > y && x > z) ? x : ((y > z) ? y : z);
  int min = (x < y && x < z) ? x : ((y < z) ? y : z);

  printf("\nThe sum of %d, %d, and %d is %d.", x, y, z, sum);
  printf("\nThe product of %d, %d, and %d is %d.", x, y, z, product);
  printf("\nThe difference of %d, %d, and %d is %d.", x, y, z, difference);
  printf("\nThe average of %d, %d, and %d is %.2f.", x, y, z, average); // Displaying average upto 2 decimal places.
  printf("\nThe maximum of %d, %d, and %d is %d.", x, y, z, max);
  printf("\nThe minimum of %d, %d, and %d is %d.\n\n", x, y, z, min);

  printf("Thanks for trying out this program with me! Until next time, chatbot out!\n");
  
  return 0;
}