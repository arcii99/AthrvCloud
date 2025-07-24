//FormAI DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>

int main() {
   float temperature;
   int i, n;
   
   printf("How many temperature readings would you like to take? ");
   scanf("%d", &n);
   
   printf("Please enter %d temperature readings in Celsius:\n", n);
   
   for (i = 1; i <= n; i++) {
       scanf("%f", &temperature);
       
       // Convert temperature to Fahrenheit
       float fahrenheit = (temperature * 9/5) + 32;
       
       // Check if temperature is above or below freezing
       if (temperature <= 0) {
           printf("Temperature %d is %.2fC (%.2fF) - It's freezing!\n", i, temperature, fahrenheit);
       } else {
           printf("Temperature %d is %.2fC (%.2fF)\n", i, temperature, fahrenheit);
       }
   }
   
   return 0;
}