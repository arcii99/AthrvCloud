//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate distance between two points on a map
double distance(double lat1, double lon1, double lat2, double lon2){
    //Convert degree to radians
    double lat1_rad = lat1*M_PI/180;
    double lon1_rad = lon1*M_PI/180;
    double lat2_rad = lat2*M_PI/180;
    double lon2_rad = lon2*M_PI/180;
    
    // Applying the formula to calculate distance between two points on a map
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    double a = pow(sin(dlat/2),2) + cos(lat1_rad)*cos(lat2_rad)*pow(sin(dlon/2),2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    double distance = 6371*c; // 6371 is radius of earth
    
    return distance;
}

int main(){
    // Initializing location of starting point
    double start_lat = 37.7749;
    double start_lon = -122.4194;
    
    // Initializing location of destination point
    double end_lat = 40.7128;
    double end_lon = -74.0060;
    
    // Printing the starting and destination coordinates
    printf("Starting Coordinates: (%lf,%lf)\n",start_lat,start_lon);
    printf("Destination Coordinates: (%lf,%lf)\n",end_lat,end_lon);
    
    // Calculating distance between the starting and destination points using the distance() function
    double dist = distance(start_lat,start_lon,end_lat,end_lon);
    
    // Printing the distance between the two points
    printf("Distance between the two points: %lf kms\n",dist);
    
    return 0;
}