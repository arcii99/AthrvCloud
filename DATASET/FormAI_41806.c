//FormAI DATASET v1.0 Category: Weather simulation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //Seed for random weather

    int temperature = rand() % 40 - 10; //Random temperature between -10 to 30
    int precipitation_chance = rand() % 11; //Random chance of precipitation between 0 to 10
    int wind_speed = rand() % 101; //Random wind speed between 0 to 100
    
    //Weather descriptions
    char* sky = (temperature < 0) ? "clear and cold" :
                (temperature < 10) ? "sunny and chilly" :
                (temperature < 20) ? "warm and pleasant" :
                (temperature < 30) ? "hot and humid" :
                "dry and burning";
    
    char* precipitation = (precipitation_chance == 0) ? "no precipitation" :
                            (precipitation_chance < 4) ? "light rain" :
                            (precipitation_chance < 7) ? "heavy rain" :
                            (precipitation_chance < 9) ? "sleet storm" :
                            "snow storm";
    
    char* wind = (wind_speed < 20) ? "calm" :
                    (wind_speed < 40) ? "breezy" :
                    (wind_speed < 60) ? "windy" :
                    (wind_speed < 80) ? "stormy" :
                    "hurricane";
    
    printf("In this post-apocalyptic world, the weather outside is %s with %s and %s winds.\n"
            ,sky, precipitation, wind);

    return 0;
}