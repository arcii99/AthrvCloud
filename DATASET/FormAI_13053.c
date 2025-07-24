//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define RADIUS 6371 //Radius of the earth in km
#define TO_RAD (3.1415926536 / 180)

/* Structure for storing the coordinates */
typedef struct {
    double lat;  //latitude
    double lon; //longitude 
} coordinates;

/* Function to calculate the distance in km between two coordinates */
double calcdist(coordinates coord1, coordinates coord2){
    double lat1, lon1, lat2, lon2, dlat, dlon, a, c, d;
    
    lat1 = coord1.lat * TO_RAD;
    lon1 = coord1.lon * TO_RAD;
    lat2 = coord2.lat * TO_RAD;
    lon2 = coord2.lon * TO_RAD;
    
    dlat = lat2 - lat1;
    dlon = lon2 - lon1;
    
    a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = RADIUS * c;
    
    return d;
}

int main(){
    coordinates current_pos = {43.6532, -79.3832}; //Toronto coordinates
    coordinates destination = {51.5074, -0.1278}; //London coordinates
    
    printf("Current position: (%.4f, %.4f)\n", current_pos.lat, current_pos.lon);
    printf("Destination: (%.4f, %.4f)\n", destination.lat, destination.lon);
    
    double distance = calcdist(current_pos, destination);
    printf("Distance to destination: %.2f km\n", distance);
    
    return 0;
}