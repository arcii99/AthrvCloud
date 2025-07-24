//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //Getting current time for random number generation
    srand(time(0));

    //Variable Initialization
    int temperature = 25;
    int humidity = 50;
    int windSpeed = 10;
    int clouds = 20;

    //Weather simulation for 7 days
    for(int i=1;i<=7;i++){

        printf("Day %d\n",i);

        //Temperature fluctuations
        temperature += rand()%7-3; //Extreme variation is +/-3 degrees
        printf("Temperature: %dC\n",temperature);

        //Humidity fluctuations
        humidity += rand()%11-5; //Extreme variation is +/-5 percentage points
        printf("Humidity: %d%%\n",humidity);

        //Wind speed fluctuations
        windSpeed += rand()%5-2; //Extreme variation is +/-2 mph
        printf("Wind Speed: %dmph\n",windSpeed);

        //Cloud coverage fluctuations
        clouds += rand()%11-5; //Extreme variation is +/-5 percent
        printf("Cloud Coverage: %d%%\n",clouds);

        //Weather condition based on parameters
        if(temperature>=30 && humidity>=60 && clouds<40){
            printf("Weather Condition: Hot and Sunny\n");
        }
        else if(temperature>=25 && humidity>=70 && clouds>=50 && windSpeed<10){
            printf("Weather Condition: Warm and Humid with Light Breezes\n");
        }
        else if(temperature<10 && humidity<=50 && clouds>=60 && windSpeed>=15){
            printf("Weather Condition: Cold and Windy with Heavy Clouds\n");
        }
        else if(temperature<15 && humidity>=70 && clouds>=80){
            printf("Weather Condition: Chilly and Damp with Overcast Skies\n");
        }
        else{
            printf("Weather Condition: Moderate Temperature and Weather.\n");
        }

        printf("-----------------------------------------------------------\n");
    }

    return 0;
}