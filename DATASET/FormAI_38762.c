//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>

int main() {
   float temperature;
   printf("Welcome to the Temperature Monitor Program!\n");
   printf("Please enter the current temperature: ");
   scanf("%f", &temperature);
   printf("You have entered %.2f degrees Celsius.\n", temperature);

   if (temperature < 0) {
      printf("Brr! It's freezing outside!\n");
   } else if (temperature >= 0 && temperature < 10) {
      printf("It's quite cold out today. Bundle up!\n");
   } else if (temperature >= 10 && temperature < 20) {
      printf("The weather is starting to warm up. A light jacket should do.\n");
   } else if (temperature >= 20 && temperature < 30) {
      printf("It's a beautiful day outside! You'll want to wear shorts and a t-shirt.\n");
   } else if (temperature >= 30 && temperature < 40) {
      printf("It's getting pretty hot outside. Stay hydrated and wear sunscreen!\n");
   } else {
      printf("It's scorching outside! Try to stay indoors if possible.\n");
   }

   return 0;
}