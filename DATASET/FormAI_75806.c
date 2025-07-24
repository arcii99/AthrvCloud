//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   srand(time(NULL));  //Seeding the random number generator with time
   
   int temperature = rand() % 50; //Generating a random temperature between 0 to 50 degree Celsius
   int humidity = rand() % 101; //Generating a random humidity percentage between 0 to 100
   
   printf("Today's weather simulation:\n"); 
   
   if(temperature >= 30 && humidity >= 60){ //Simulating a hot and humid day
       printf("It's a hot and humid day today. Stay hydrated and cool!\n");
   } else if(temperature <= 10 && humidity <= 30){ //Simulating a cold and dry day
       printf("It's a cold and dry day today. Wear warm clothes and keep yourself moisturized.\n");
   } else if(temperature >= 10 && temperature < 20){ //Simulating a cool day
       printf("It's a cool day today. Enjoy the pleasant weather!\n");
   } else if(temperature >= 20 && temperature < 30 && humidity <= 60){ //Simulating a warm and dry day
       printf("It's a warm and dry day today. Perfect for outdoor activities!\n");
   } else if(temperature >= 20 && temperature < 30 && humidity > 60){ //Simulating a warm and humid day
       printf("It's a warm and humid day today. Enjoy the weather but make sure to stay hydrated!\n");
   } else { //Simulating other weather conditions
       printf("The weather is unpredictable today. Stay prepared for any weather conditions.\n");
   }
   
   return 0;
}