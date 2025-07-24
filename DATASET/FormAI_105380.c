//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>

int main() {
  int a,b,c; // Declare three integer variables
  printf("Please enter the values of a, b and c: "); //Prompt the user to input values
  scanf("%d %d %d", &a, &b, &c); //Store those values in the respective variables

  //Add the three numbers and store in the variable sum
  int sum = a + b + c; 

  //Calculate the average of the three numbers
  float avg = (float)(sum)/3;

  //Display the sum and average values to the user
  printf("The sum of %d, %d, and %d is: %d\n", a, b, c, sum);
  printf("The average of %d, %d, and %d is: %.2f\n", a, b, c, avg);

  //Find the maximum value among the three numbers and display it to the user
  int max = a;
  if(b > max) {
    max = b;
  }
  if(c > max) {
    max = c;
  }
  printf("The maximum value among %d, %d, and %d is: %d\n", a, b, c, max);

  //Find the minimum value among the three numbers and display it to the user
  int min = a;
  if(b < min) {
    min = b;
  }
  if(c < min) {
    min = c;
  }
  printf("The minimum value among %d, %d, and %d is: %d\n", a, b, c, min);

  //Calculate the product of the three numbers and display it to the user
  int prod = a * b * c;
  printf("The product of %d, %d, and %d is: %d\n", a, b, c, prod);

  return 0;
}