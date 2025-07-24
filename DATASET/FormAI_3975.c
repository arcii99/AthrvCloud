//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

struct Point{
    double x;
    double y;
};

double toRadians(double degree){
    return (degree * PI / 180);
}

//Get the distance between two points
double distance(struct Point p1, struct Point p2){
    double lat1 = p1.x;
    double lat2 = p2.x;
    double lon1 = p1.y;
    double lon2 = p2.y;

    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);
    lon1 = toRadians(lon1);
    lon2 = toRadians(lon2);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;  //6371 is the radius of earth in km
    return distance;
}

//Print the distance between two points
void printDistance(struct Point p1, struct Point p2){
    double distanceKm = distance(p1, p2);
    printf("The distance between Point 1 and Point 2 is: %lf km\n", distanceKm);
}

int main(){
    struct Point p1, p2;
    printf("Enter the latitude and longitude of Point 1: \n");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Enter the latitude and longitude of Point 2: \n");
    scanf("%lf %lf", &p2.x, &p2.y);
    printDistance(p1, p2);
    return 0;
}