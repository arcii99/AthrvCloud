//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int temperature = 25;
    char *weather = "Sunny";
    srand(time(0));
    int chanceOfRain = rand() % 100;

    if(chanceOfRain <= 30){
        weather = "Rainy";
        temperature = 20 + rand() % 5;
    }else if(chanceOfRain <= 60){
        weather = "Cloudy";
        temperature = 22 + rand() % 3;
    }else{
        weather = "Sunny";
        temperature = 25 + rand() % 5;
    }

    printf("Today's weather is %s with a temperature of %dC\n", weather, temperature);

    return 0;
}