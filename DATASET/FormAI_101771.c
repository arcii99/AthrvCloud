//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>

int main() {
   int celsius, fahrenheit;

   printf("Enter temperature in Celsius: ");
   scanf("%d", &celsius);

   fahrenheit = (celsius * 9/5) + 32;

   printf("\nTemperature in Fahrenheit: %d\n", fahrenheit);

   return 0;
}