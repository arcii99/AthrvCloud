//FormAI DATASET v1.0 Category: Educational ; Style: grateful
#include <stdio.h>

int main() {
  printf("Hello, and welcome to my C programming example program!\n");

  // Creating an array of numbers
  int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Computing the average of the numbers
  int sum = 0;
  double avg;

  for (int i = 0; i < 10; i++) {
    sum += nums[i];
  }
  avg = ((double) sum) / 10;

  printf("The average of the numbers in the array is: %f\n", avg);

  printf("Now, let's try something a bit fancier...\n");

  // Creating a matrix of numbers
  int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  // Finding the determinant of the matrix
  int det = 0;

  det = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) -
        matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0])) +
        matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));

  printf("The determinant of the matrix is: %d\n", det);

  printf("I hope you enjoyed learning something new in C programming today! Keep practicing and learning more!\n");

  return 0;
}