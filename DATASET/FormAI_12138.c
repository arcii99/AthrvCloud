//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
   float temperature;
   
   printf("Please enter temperature in Celsius: ");
   scanf("%f", &temperature);
    
   if(temperature < 0){
       printf("It's too cold, better bundle up\n");
   }
    
   else if(temperature >= 0 && temperature <= 20){
       printf("It's a bit chilly, wear a jacket\n");
   }
    
   else if(temperature >= 21 && temperature <= 30){
       printf("It's a nice day, enjoy the weather\n");
   }
    
   else if(temperature >= 31 && temperature <= 40){
       printf("It's getting hot, stay hydrated\n");
   }
    
   else{
       printf("It's too hot, stay indoors\n");
   }

   return 0;
}