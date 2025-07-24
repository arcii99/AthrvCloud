//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to calculate distance between two coordinates
double distance(double lat1, double long1, double lat2, double long2){
    double earthRadius = 6371; //km
    double dLat = (lat2-lat1) * M_PI / 180;
    double dLong = (long2-long1) * M_PI / 180;
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * sin(dLong/2) * sin(dLong/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = earthRadius * c;
    return distance; //kilometers
}

//main function
int main(){
    double startLat, startLong, endLat, endLong;
    printf("Enter starting latitude: ");
    scanf("%lf", &startLat);
    printf("Enter starting longitude: ");
    scanf("%lf", &startLong);
    printf("Enter destination latitude: ");
    scanf("%lf", &endLat);
    printf("Enter destination longitude: ");
    scanf("%lf", &endLong);
    printf("\nCalculating route...\n");
    printf("Distance to destination: %.2lf km\n", distance(startLat, startLong, endLat, endLong));
    printf("Directions:\n");
    if(startLat > endLat){
        printf("Go south for %.2lf km\n", distance(startLat, startLong, endLat, startLong));
    }
    else{
        printf("Go north for %.2lf km\n", distance(startLat, startLong, endLat, startLong));
    }
    if(startLong > endLong){
        printf("Go west for %.2lf km\n", distance(endLat, startLong, endLat, endLong));
    }
    else{
        printf("Go east for %.2lf km\n", distance(endLat, startLong, endLat, endLong));
    }
    printf("You have arrived at your destination!\n");
    return 0;
}