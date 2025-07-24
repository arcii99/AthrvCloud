//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
//GPS Navigation Simulation

//Creating structure to hold longitude and latitude information
typedef struct{
    float longitude;
    float latitude;
} Location;

//Function to calculate distance between two points
float distanceBetweenPoints(Location point1, Location point2){
    float distance = sqrt(pow((point1.longitude-point2.longitude),2) + pow((point1.latitude-point2.latitude),2));
    return distance;
}

int main(){
    //Creating an array of locations to hold GPS coordinates
    Location locations[5] = {{34.0522, -118.2437}, {40.7128, -74.0060}, {41.8818, -87.6232}, {37.7749, -122.4194}, {51.5074, -0.1278}};  
    
    int currentLocation = 0; //Starting at the first location
    Location destination; //Variable to hold user input for destination
    float totalDistanceTraveled = 0; //Variable to hold the total distance traveled
    
    printf("Welcome to GPS Navigation Simulation!\n\n");
    
    //Loop until user reaches destination
    while(currentLocation != 4){
        printf("Current Location: (%f, %f)\n", locations[currentLocation].latitude, locations[currentLocation].longitude);
        printf("Enter latitude of destination: ");
        scanf("%f", &destination.latitude);
        printf("Enter longitude of destination: ");
        scanf("%f", &destination.longitude);
        
        float distanceToDestination = distanceBetweenPoints(locations[currentLocation], destination);
        totalDistanceTraveled += distanceToDestination;
        
        printf("Traveling %.2f miles to destination...\n", distanceToDestination);
        printf("You have traveled %.2f miles in total.\n\n", totalDistanceTraveled);
        
        //Update current location
        currentLocation++;
    }
    
    printf("Congratulations! You have reached your final destination.\n");
    printf("You traveled a total of %.2f miles.\n", totalDistanceTraveled);
    
    return 0;
}