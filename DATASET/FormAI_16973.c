//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>

int main() {
   int temperature;
   printf("Greetings, fair traveler! Welcome to the kingdom of Thermometeria, where we monitor the temperature with the finest technology of the medieval age. \n");
   printf("What is the current temperature in Celsius degrees? \n");
   scanf("%d", &temperature);
   
   if (temperature >= 20 && temperature <= 30) {
      printf("The temperature seems to be just perfect for a nice day at the marketplace! Enjoy your day, noble traveler. \n");
   } else if (temperature < 20) {
      printf("It's quite chilly today! Make sure to wear your woolen tunic and scarf. \n");
   } else if (temperature > 30) {
      printf("By the holy flames of the dragon, it's scorching hot today! Seek shade and drink plenty of water to stay safe. \n");
   } else {
      printf("Hark, something is amiss! The temperature reading is unlike anything we've seen before. Perhaps the device needs a checkup by the royal scribe. \n");
   }
   
   printf("Thank you for visiting Thermometeria. Fare thee well, brave traveler! \n");
   return 0;
}