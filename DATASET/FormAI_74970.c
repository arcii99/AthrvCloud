//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
   int temp;

   printf("Enter current temperature in Celsius: ");
   scanf("%d", &temp);

   printf("Current temperature in Celsius: %d\n", temp);
   printf("Current temperature in Fahrenheit: %.2f\n", (float)temp * 1.8 + 32);

   if (temp < 0) {
      printf("Brrr, it's freezing in here! Turn up the heat.\n");
   }
   else if (temp >= 0 && temp < 20) {
      printf("It's a bit chilly in here. Put on a sweater.\n");
   }
   else if (temp >= 20 && temp <= 30) {
      printf("Ah, this is the perfect temperature. Enjoy!\n");
   }
   else {
      printf("It's boiling in here! Turn down the heat.\n");
   }

   return 0;
}