//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i,j;
   float temperature[24];

   srand(time(NULL));

   printf("Hour  Temperature\n");

   for(i=0;i<24;i++)
   {
      temperature[i] = (float)(rand()%301)/10 - 15; // temperature ranges from -15C to 15C
      printf("%2d:00   %5.1fC\n", i, temperature[i]); 
   }

   float maxTemp = -1000;
   float minTemp = 1000;
   float average = 0;

   for(i=0;i<24;i++)
   {
      if(temperature[i] > maxTemp)
         maxTemp = temperature[i];
      if(temperature[i] < minTemp)
         minTemp = temperature[i];

      average += temperature[i];
   }

   average /= 24.0; 

   printf("\nMax temperature: %5.1fC\n", maxTemp);
   printf("Min temperature: %5.1fC\n", minTemp);
   printf("Average temperature: %5.1fC\n", average);

   return 0;
}