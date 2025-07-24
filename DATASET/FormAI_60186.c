//FormAI DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include <stdio.h>

int main(void) {
  float celsius;
  int tempCount = 0;
  float tempTotal = 0;
  float tempAverage = 0;

  printf("Welcome to the Celsius Temperature Monitor!\n");

  do {
    printf("Enter the temperature in Celsius or press -999 to exit: ");
    scanf("%f", &celsius);

    if (celsius != -999) {
      tempCount++;
      tempTotal += celsius;
      tempAverage = tempTotal / tempCount;

      printf("\nYou entered %.2f degrees Celsius.", celsius);
      printf("\nThe current average temperature is %.2f degrees Celsius.\n\n", tempAverage);
    }
  } while (celsius != -999);

  printf("Thank you for using the Celsius Temperature Monitor!");

  return 0;
}