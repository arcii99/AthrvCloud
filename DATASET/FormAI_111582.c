//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>

int main() {
   float temperature;
   
   printf("Please enter the current temperature: ");
   scanf("%f", &temperature);
   
   if (temperature >= 30) {
      printf("It's a hot day!\n");
   } else if (temperature < 30 && temperature > 15) {
      printf("It's a nice day!\n");
   } else {
      printf("It's a bit chilly today.\n");
   }
   
   return 0;
}