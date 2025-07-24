//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
// I am a geometric algorithms example program with introspective style
// In this program, I will calculate the area of a rectangle and a triangle
// First, I will prompt the user to enter the dimensions of the rectangle and triangle
// Then, I will compute their respective areas and display the results

#include <stdio.h>

int main() {
  // Let's introduce ourselves to the user
  printf("Hello! I am a geometric algorithms program.\n");
  
  // Now, let's prompt the user to input the length and width of the rectangle
  printf("Please enter the length of the rectangle: ");
  double rectLength;
  scanf("%lf", &rectLength);
  
  printf("Please enter the width of the rectangle: ");
  double rectWidth;
  scanf("%lf", &rectWidth);
  
  // Let's compute the area of the rectangle
  double rectArea = rectLength * rectWidth;
  
  // Display the area of the rectangle to the user
  printf("The area of the rectangle is: %lf\n", rectArea);
  
  // Now, let's prompt the user to input the base and height of the triangle
  printf("Please enter the base of the triangle: ");
  double triBase;
  scanf("%lf", &triBase);
  
  printf("Please enter the height of the triangle: ");
  double triHeight;
  scanf("%lf", &triHeight);
  
  // Let's compute the area of the triangle
  double triArea = 0.5 * triBase * triHeight;
  
  // Display the area of the triangle to the user
  printf("The area of the triangle is: %lf\n", triArea);
  
  // Finally, let's say goodbye to the user
  printf("Thank you for using my program. Goodbye!\n");
  
  // Return 0 to indicate successful termination of the program
  return 0;
}