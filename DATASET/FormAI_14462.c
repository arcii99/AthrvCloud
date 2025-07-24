//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   float temp;
   printf("Enter the temperature in Celsius: ");
   scanf("%f",&temp);
   printf("The temperature in Celsius is %0.2f\n",temp);
   
   float f_temp = (temp * 9/5) + 32;
   printf("The temperature in Fahrenheit is %0.2f\n",f_temp);
   
   if(f_temp < 32)
       printf("It's very cold outside, make sure to wear a thick jacket!\n");
   else if(f_temp < 50)
       printf("It's somewhat cold outside, wearing a light jacket is recommended.\n");
   else if(f_temp < 70)
       printf("The weather is pleasant, you can wear a light sweater or a t-shirt.\n");
   else if(f_temp < 85)
       printf("The weather is warm, you can wear a light dress or a t-shirt.\n");
   else
       printf("It's very hot outside, wear light and loose clothing.\n");
   
   return 0;
}