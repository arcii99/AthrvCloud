//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void loadBaggageToTruck();
void transportBagsToPlane();
void unloadBagsFromTruck();


int current_stage = 0, total_stages = 3;


int main()
{
    printf("Welcome to Airport Baggage Handling Simulation!\n");
    printf("Please wait while your bags are being loaded.\n");

    loadBaggageToTruck();  

    return 0;
}


void loadBaggageToTruck()
{
    printf("\nBags are being loaded to the truck.\n");
    sleep(1);
    printf("Loading bags successfully completed!\n");

    if(current_stage < total_stages)
    {
        printf("\nPlease wait while bags are being transported to the plane.\n");
        transportBagsToPlane();
    }
    else
    {
        printf("\nAll bags successfully transported to the plane. Have a nice flight!\n");
        return;
    }
}


void transportBagsToPlane()
{
    printf("\nBags are being transported.\n");
    sleep(2);
    printf("Transporting bags successfully completed!\n");

    current_stage++;

    if(current_stage < total_stages)
    {
        unloadBagsFromTruck();
    }
    else
    {
        printf("\nAll bags successfully transported to the plane. Have a nice flight!\n");
        return;
    }
}


void unloadBagsFromTruck()
{
    printf("\nBags are being unloaded from the truck.\n");
    sleep(1);
    printf("Unloading bags successfully completed!\n");

    if(current_stage < total_stages)
    {
        printf("\nPlease wait while bags are being transported to the plane.\n");
        transportBagsToPlane();
    }
    else
    {
        printf("\nAll bags successfully transported to the plane. Have a nice flight!\n");
        return;
    }
}