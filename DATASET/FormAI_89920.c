//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
/* GPS Navigation Simulation */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //initialize random number generator with time
    
    float latitude = 37.7749; // San Francisco latitude
    float longitude = -122.4194; // San Francisco longitude
    
    printf("You are currently located at latitude: %f and longitude: %f\n", latitude, longitude);
    
    for(int i=0; i<10; i++){ //simulate travel for 10 times
        float moveLat = ((float)rand()/(float)(RAND_MAX)) * 0.5 - 0.25; //get random movement within 0.25 degrees (latitude)
        float moveLong = ((float)rand()/(float)(RAND_MAX)) * 0.5 - 0.25; //get random movement within 0.25 degrees (longitude)
        
        latitude += moveLat;
        longitude += moveLong;
        
        printf("You have moved to latitude: %f and longitude: %f\n", latitude, longitude);
        
        if(latitude > 38 || longitude < -123){ //If user has gone out of San Francisco bounds
            printf("You have gone out of San Francisco bounds.\n");
            break; //stop simulation
        }
    }
    
    printf("GPS Navigation Simulation Completed\n");
    
    return 0;
}