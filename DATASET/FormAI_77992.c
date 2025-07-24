//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //setting up seed for random number generator
    srand(time(NULL));

    //generating random conspiracy theory
    int num = rand() % 10; //generating a number between 0 and 9
    char *theory;

    //assigning conspiracy theory based on random number
    switch(num) {
        case 0:
            theory = "The moon landing was faked by the government.";
            break;
        case 1:
            theory = "The government is using chemtrails to control our minds.";
            break;
        case 2:
            theory = "The earth is actually flat.";
            break;
        case 3:
            theory = "Aliens have been secretly living among us.";
            break;
        case 4:
            theory = "9/11 was an inside job.";
            break;
        case 5:
            theory = "The Illuminati controls the world.";
            break;
        case 6:
            theory = "The vaccine for COVID-19 is actually a way to implant microchips in our bodies.";
            break;
        case 7:
            theory = "The Bermuda Triangle is a portal to another dimension.";
            break;
        case 8:
            theory = "The government is hiding evidence of time travel.";
            break;
        case 9:
            theory = "The pyramids were built by aliens.";
            break;
        default:
            theory = "Error: conspiracy not found.";
            break;
    }

    //printing out conspiracy theory
    printf("Did you know? %s\n", theory);
    
    return 0;
}