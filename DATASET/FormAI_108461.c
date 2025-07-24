//FormAI DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(0));
    int minTemp = -20;
    int maxTemp = 40;
    int rainChance = 40;
    int snowChance = 50;
    int mostlyCloudyChance = 30;
    int partlyCloudyChance = 50;
    int sunnyChance = 20;

    int currentTemp = rand() % (maxTemp - minTemp + 1) + minTemp;

    int weatherType = rand() % 100 + 1;

    if (weatherType <= rainChance) 
    {
        printf("The current temperature is %d degrees and it's raining outside.\n", currentTemp);
    } 
    else if (weatherType <= snowChance) 
    {
        printf("The current temperature is %d degrees and it's snowing outside.\n", currentTemp);
    } 
    else if (weatherType <= mostlyCloudyChance) 
    {
        printf("The current temperature is %d degrees and it's mostly cloudy outside.\n", currentTemp);
    } 
    else if (weatherType <= partlyCloudyChance) 
    {
        printf("The current temperature is %d degrees and it's partly cloudy outside.\n", currentTemp);
    } 
    else 
    {
        printf("The current temperature is %d degrees and it's sunny outside.\n", currentTemp);
    }

    return 0;
}