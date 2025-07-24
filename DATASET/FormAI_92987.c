//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function to generate random coordinates within given limits
int generateRandomCoordinates(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    srand(time(0));

    //Generating random coordinates for simulation purposes
    int latitude = generateRandomCoordinates(-90, 90);
    int longitude = generateRandomCoordinates(-180, 180);

    printf("Welcome to the Futuristic GPS Navigation Simulation!\n");
    printf("Your current coordinates are: Latitude - %d, Longitude - %d\n\n", latitude, longitude);

    //Accepting input for destination coordinates
    int destLat, destLong;
    printf("Enter your destination coordinates (latitude and longitude): ");
    scanf("%d %d", &destLat, &destLong);

    printf("\nCalculating optimal route to your destination...\n");

    //Assuming vehicle moves at a constant speed of 50km/hr
    float distance = sqrt(pow((destLat - latitude), 2) + pow((destLong - longitude), 2));
    float time = distance / 50;

    printf("\nDistance to destination: %.2f km", distance);
    printf("\nEstimated time of arrival: %.2f hours\n\n", time);

    //Generating a random futuristic landmark as a point of interest
    char landmarks[5][50] = {"Sky Tower", "Hyperloop Station", "Quantum Data Center", "Space Elevator", "Fusion Reactor"};
    int randomIndex = rand() % 5;
    char landmark[50];
    strcpy(landmark, landmarks[randomIndex]);

    printf("As you travel towards your destination, be sure to check out the following futuristic landmark: %s\n", landmark);

    return 0;
}