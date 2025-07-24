//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int rand_num;
    char* conspiracy = "";

    // Generate random number to choose a conspiracy theory
    rand_num = rand() % 10;

    // Generate conspiracy theory based on random number
    switch(rand_num)
    {
        case 0:
            conspiracy = "The moon landing was faked by the US government.";
            break;
        case 1:
            conspiracy = "The Illuminati controls the world's governments.";
            break;
        case 2:
            conspiracy = "Chemtrails are used to control the population.";
            break;
        case 3:
            conspiracy = "COVID-19 is a bioweapon created in a lab.";
            break;
        case 4:
            conspiracy = "The government is hiding the existence of extraterrestrial life.";
            break;
        case 5:
            conspiracy = "The earth is flat.";
            break;
        case 6:
            conspiracy = "The 9/11 attacks were an inside job.";
            break;
        case 7:
            conspiracy = "The world will end on December 21st, 2012.";
            break;
        case 8:
            conspiracy = "The Bermuda Triangle is a portal to another dimension.";
            break;
        case 9:
            conspiracy = "The COVID-19 vaccine has a microchip to track people.";
            break;
    }

    // Print the chosen conspiracy theory
    printf("Did you know? %s\n\n", conspiracy);

    return 0;
}