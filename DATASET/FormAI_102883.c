//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>

int main() {
  float temp_c;
  printf("Welcome to the Temperature Monitor Program.\n");
  printf("Please enter the current temperature in Celsius: ");
  scanf("%f", &temp_c);
  printf("\nThe current temperature in Celsius is %.2f degrees.\n", temp_c);
  
  if (temp_c > 28) {
    printf("WARNING: The temperature is higher than the recommended limit of 28 degrees Celsius.\n");
  }
  else if (temp_c < 18) {
    printf("WARNING: The temperature is lower than the recommended limit of 18 degrees Celsius.\n");
  }
  else {
    printf("The temperature is within the recommended range of 18 to 28 degrees Celsius.\n");
  }

  printf("\nThank you for using the Temperature Monitor Program. Stay safe and cool!\n");
  return 0;
}