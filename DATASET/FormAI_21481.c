//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand((unsigned)time(NULL));
   int temperature = rand() % 50 + 1; // generate random temperature between 1 and 50
   
   char* weather;
   
   if (temperature >= 30) {
      weather = "hot and sunny";
   } else if (temperature >= 20 && temperature < 30) {
      weather = "warm and pleasant";
   } else if (temperature >= 10 && temperature < 20) {
      weather = "cool and breezy";
   } else {
      weather = "cold and cloudy";
   }
   
   printf("Today's temperature is: %d degrees Celsius\n", temperature);
   printf("The weather is %s\n", weather);
   
   return 0;
}