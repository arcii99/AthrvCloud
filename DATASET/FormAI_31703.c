//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>

int main() {
   float temperature;

   // input temperature from user
   printf("Enter current temperature: ");
   scanf("%f", &temperature);

   // analyze temperature and display appropriate message
   if (temperature < 0) {
       printf("It's freezing outside!");
   } else if (temperature >= 0 && temperature < 10) {
       printf("It's very cold outside.");
   } else if (temperature >= 10 && temperature < 20) {
       printf("It's a bit cold outside.");
   } else if (temperature >= 20 && temperature < 30) {
       printf("It's a nice temperature outside.");
   } else {
       printf("It's getting quite hot outside!");
   }

   return 0;
}