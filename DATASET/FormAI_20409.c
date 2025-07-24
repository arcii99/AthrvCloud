//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
  // Inquisitive prompt
  printf("Hey there! Ready for a challenging math exercise?\n");
  printf("Let's generate a random number between 1 and 10...\n");
  
  // Generate random number
  int num = rand() % 10 + 1;
  printf("Got it! Your number is %d.\n", num);
  
  // Instruct user to round to nearest integer
  printf("Now, round it to the nearest whole number.\n");
  double rounded = round(num);
  
  // Confirm rounded value
  printf("You rounded to %0.0lf. Great job!\n", rounded);
  
  // Instruct user to find square root of rounded value
  printf("Now, find the square root of %0.0lf.\n", rounded);
  double sqrtVal = sqrt(rounded);
  
  // Confirm square root value
  printf("Your square root value is %0.2lf. Keep going!\n", sqrtVal);
  
  // Instruct user to find the absolute value of their answer
  printf("Let's find the absolute value of that number.\n");
  double absVal = fabs(sqrtVal);
  
  // Confirm absolute value
  printf("Your absolute value is %0.2lf. Amazing work!\n", absVal);
  
  // Instruct user to find the power of their answer
  printf("Lastly, let's find the value of %0.2lf raised to the power of 3.\n", absVal);
  double powVal = pow(absVal, 3);
  
  // Confirm power value
  printf("Your final value is %0.2lf. Incredible!\n", powVal);
  
  return 0;
}