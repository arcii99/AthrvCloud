//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature, humidity;
   srand(time(0));
   temperature = rand() % 40; // randomly generates temperature from 0 to 39 Celsius
   humidity = rand() % 100; // randomly generates humidity from 0 to 99 percent
   
   printf("Today's weather conditions:\n");
   printf("Temperature: %dC\n", temperature);
   printf("Humidity: %d%%\n", humidity);
   
   // determine the weather condition based on the temperature and humidity
   if(temperature <= 8 && humidity <= 30) {
      printf("The weather is extremely cold and dry.\n");
   } else if(temperature <= 8 && humidity > 30 && humidity <= 50) {
      printf("The weather is cold and dry.\n");
   } else if(temperature <= 8 && humidity > 50) {
      printf("The weather is cold and humid.\n");
   } else if(temperature > 8 && temperature <= 16 && humidity <= 30) {
      printf("The weather is very cool and dry.\n");
   } else if(temperature > 8 && temperature <= 16 && humidity > 30 && humidity <= 50) {
      printf("The weather is cool and dry.\n");
   } else if(temperature > 8 && temperature <= 16 && humidity > 50) {
      printf("The weather is cool and humid.\n");
   } else if(temperature > 16 && temperature <= 24 && humidity <= 30) {
      printf("The weather is pleasant and dry.\n");
   } else if(temperature > 16 && temperature <= 24 && humidity > 30 && humidity <= 50) {
      printf("The weather is pleasant and slightly humid.\n");
   } else if(temperature > 16 && temperature <= 24 && humidity > 50) {
      printf("The weather is pleasant and humid.\n");
   } else if(temperature > 24 && temperature <= 32 && humidity <= 30) {
      printf("The weather is warm and dry.\n");
   } else if(temperature > 24 && temperature <= 32 && humidity > 30 && humidity <= 50) {
      printf("The weather is warm and slightly humid.\n");
   } else if(temperature > 24 && temperature <= 32 && humidity > 50) {
      printf("The weather is warm and humid.\n");
   } else if(temperature > 32 && temperature <= 40 && humidity <= 30) {
      printf("The weather is hot and dry.\n");
   } else if(temperature > 32 && temperature <= 40 && humidity > 30 && humidity <= 50) {
      printf("The weather is hot and slightly humid.\n");
   } else if(temperature > 32 && temperature <= 40 && humidity > 50) {
      printf("The weather is hot and humid.\n");
   } else {
      printf("The weather conditions cannot be determined.\n");
   }
   
   return 0;
}