//FormAI DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>

int main() {
   int temp;
   printf("Enter the temperature in Celsius: ");
   scanf("%d", &temp);
   printf("\nTemperature in Celsius: %d°C", temp);
   printf("\nTemperature in Fahrenheit: %d°F", (temp * 9/5) + 32);
   if (temp <= 0) {
      printf("\nIt's freezing outside! Be sure to wear a coat.");
   } else if (temp > 0 && temp <= 20) {
      printf("\nIt's a bit cold outside, bring a sweater.");
   } else if (temp > 20 && temp <= 30) {
      printf("\nIt's a perfect day to go for a walk.");
   } else if (temp > 30 && temp <= 40) {
      printf("\nIt's quite hot outside, stay hydrated.");
   } else {
      printf("\nIt's scorching hot outside, avoid going out if possible.");
   }
   return 0;
}