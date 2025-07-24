//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temp, min_temp = 100, max_temp = -100, sum_temp = 0, count = 0;
   float avg_temp = 0.0;

   time_t currentTime;
   struct tm *localTime;

   time( &currentTime );
   localTime = localtime( &currentTime );
   printf( "Temperature Monitor for %s\n", asctime( localTime ) );

   while (1) {
      printf("Enter temperature in Celsius (-100 to 100): ");
      scanf("%d", &temp);

      if (temp == -999) {
         break;
      }

      if (temp < -100 || temp > 100) {
         printf("Invalid input!\n");
         continue;
      }

      count++;
      sum_temp += temp;
      if (temp < min_temp) {
         min_temp = temp;
      }
      if (temp > max_temp) {
         max_temp = temp;
      }

      avg_temp = (float) sum_temp / count;

      printf("Temperature: %d °C\n", temp);
      printf("Minimum temperature: %d °C\n", min_temp);
      printf("Maximum temperature: %d °C\n", max_temp);
      printf("Average temperature: %.2f °C\n", avg_temp);
   }

   return 0;
}