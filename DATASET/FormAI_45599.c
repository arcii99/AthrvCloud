//FormAI DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h> // for rand and srand
#include <time.h> // for time function

// Function declarations
int generateRandomNumber(int max);
double calculateTriangleArea(double base, double height);
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);

// Main function
int main() {
  srand(time(0)); // Seed the random number generator with the current time
  int num1 = generateRandomNumber(10); // Generate a random number between 0 and 10
  int num2 = generateRandomNumber(10); // Generate another random number between 0 and 10

  printf("Let's practice some geometry!\n");
  printf("We have a triangle with a base of %d and a height of %d.\n", num1, num2);
  double triangleArea = calculateTriangleArea(num1, num2); // Calculate the area of the triangle
  printf("The area of the triangle is %.2f.\n", triangleArea);

  printf("We also have a circle with a radius of %d.\n", num1);
  double circleArea = calculateCircleArea(num1); // Calculate the area of the circle
  printf("The area of the circle is %.2f.\n", circleArea);

  printf("Finally, we have a rectangle with a length of %d and a width of %d.\n", num1, num2);
  double rectangleArea = calculateRectangleArea(num1, num2); // Calculate the area of the rectangle
  printf("The area of the rectangle is %.2f.\n", rectangleArea);

  return 0;
}

// Function to generate a random integer between 0 and max
int generateRandomNumber(int max) {
  return rand() % (max + 1); // Note: add 1 to include max in the possible values
}

// Function to calculate the area of a triangle given its base and height
double calculateTriangleArea(double base, double height) {
  return 0.5 * base * height;
}

// Function to calculate the area of a circle given its radius
double calculateCircleArea(double radius) {
  return 3.14 * radius * radius; // Note: using a constant value for pi here
}

// Function to calculate the area of a rectangle given its length and width
double calculateRectangleArea(double length, double width) {
  return length * width;
}