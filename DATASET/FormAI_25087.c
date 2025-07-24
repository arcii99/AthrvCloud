//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>

int main(void) {
  printf("Welcome to the Triangular Madness!\n");
  printf("Enter the length of first side of your triangle: ");
  int a;
  scanf("%d", &a);
  printf("Enter the length of second side of your triangle: ");
  int b;
  scanf("%d", &b);
  printf("Enter the length of third side of your triangle: ");
  int c;
  scanf("%d", &c);

  if (a <= 0 || b <= 0 || c <= 0) {
    printf("Oops! Sides can't be negative or zero!\n");
    return 1;
  }

  if (a + b <= c || a + c <= b || b + c <= a) {
    printf("Oops! These sides can't form a triangle!\n");
    return 1;
  }

  printf("Congratulations! These sides form a valid triangle!\n");

  double s = (double)(a + b + c) / 2;
  double area = s * (s - a) * (s - b) * (s - c);
  printf("The area of the triangle is: %lf\n", area);

  double perimeter = (double)(a + b + c);
  printf("The perimeter of the triangle is: %lf\n", perimeter);

  double angle1 = (double)(a * a + b * b - c * c) / (2 * a * b);
  double angle2 = (double)(b * b + c * c - a * a) / (2 * b * c);
  double angle3 = (double)(c * c + a * a - b * b) / (2 * c * a);
  printf("The angles of the triangle are: %lf, %lf, %lf degrees\n", 
         angle1 * 180 / 3.14159, angle2 * 180 / 3.14159, angle3 * 180 / 3.14159);
  
  printf("Thank you for using Triangular Madness. See you soon!\n");

  return 0;
}