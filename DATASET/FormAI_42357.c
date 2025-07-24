//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h> // Include standard input-output library
#include <stdlib.h> // Include standard library
#include<time.h> // Include time library for random numbers

int main()
{
    srand(time(0)); // Seed time

    printf("Welcome to Procedural Space Adventure!\n\n");

    // Generate random planet properties
    int planetNameNum = rand() % 10 + 1;
    int planetSize = rand() % 100 + 1;
    int planetTemp = rand() % 300 + 50;
    int planetOxygen = rand() % 100 + 1;
    int planetAlienNum = rand() % 50000 + 1;

    // Display planet properties
    printf("Your landing on a planet named ");

    switch (planetNameNum)
    {
        case 1:
            printf("Aurelia");
            break;
        case 2:
            printf("Cryso");
            break;
        case 3:
            printf("Durin");
            break;
        case 4:
            printf("Erebos");
            break;
        case 5:
            printf("Feronia");
            break;
        case 6:
            printf("Gallaxia");
            break;
        case 7:
            printf("Hydros");
            break;
        case 8:
            printf("Infinity");
            break;
        case 9:
            printf("Jovaria");
            break;
        case 10:
            printf("Klastos");
            break;
        default:
            printf("Unknown");
            break;
    }

    printf(", which is %d kilometers in size.\n", planetSize);
    printf("The temperature on this planet is %d degrees Celsius.\n", planetTemp);
    printf("There is %d%% oxygen present in the atmosphere.\n", planetOxygen);
    printf("You are not alone on this planet. There are %d alien species living here!\n", planetAlienNum);

    // Display mission instructions
    printf("\nYour mission is to gather resources from this planet while avoiding dangerous alien species.\n");
    printf("You can gather resources by exploring the planet, scanning the environment for minerals, and avoiding alien attacks.\n");
    printf("Good luck, and don't get too close to those aliens!\n");

    return 0;
}