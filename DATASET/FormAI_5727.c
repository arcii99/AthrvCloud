//FormAI DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h> // for printf and scanf functions
#include <stdlib.h> // for exit function
#include <unistd.h> // for sleep function

int main() {
   int i;
   float temp, sum = 0, avg;
   printf("Welcome to the Temperature Monitor Program!\n\n");

   for (i = 1; i <= 10; i++) {
      printf("Enter Temperature %d: ", i);
      scanf("%f", &temp);

      if (temp < -273) { // absolute zero temperature
         printf("Temperature should not be below absolute zero (-273 C).\n");
         exit(0);
      } else {
         sum += temp;
      }

      printf("\n");
      sleep(1); // delay 1 second
   }
   
   avg = sum / 10;
   printf("Average Temperature: %.2f C\n", avg);

   if (avg < 0) {
      printf("It's freezing outside, better stay indoors!\n");
   } else if (avg >= 0 && avg < 15) {
      printf("It's a bit chilly outside, wear a sweater!\n");
   } else if (avg >= 15 && avg < 25) {
      printf("It's a nice and comfortable day, enjoy it!\n");
   } else {
      printf("It's a hot day outside, stay hydrated!\n");
   }

   return 0;
}