//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   float temp;
   char scale[4];
   char message[50];

   printf("Enter temperature in Celsius or Fahrenheit: ");
   scanf("%f %s", &temp, scale);

   if (strcmp(scale, "C") == 0 || strcmp(scale, "c") == 0)
   {
      if (temp < -273.15)
      {
         sprintf(message, "%.2f°C is below absolute zero!", temp);
      }
      else
      {
         sprintf(message, "%.2f°C is %.2f°F", temp, (temp * 1.8) + 32);
      }
   }
   else if (strcmp(scale, "F") == 0 || strcmp(scale, "f") == 0)
   {
      if (temp < -459.67)
      {
         sprintf(message, "%.2f°F is below absolute zero!", temp);
      }
      else
      {
         sprintf(message, "%.2f°F is %.2f°C", temp, (temp - 32) / 1.8);
      }
   }
   else
   {
      sprintf(message, "Invalid scale entered.");
   }

   printf("%s\n", message);

   return 0;
}