//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.141592653589793

//Structure to store the latitude and longitude of a point
typedef struct {
    double latitude;
    double longitude;
} GPS_Point;

//Function to calculate distance between two GPS points in kilometers
double calculate_distance(GPS_Point p1, GPS_Point p2){
    double lat1 = p1.latitude * PI / 180;
    double lon1 = p1.longitude * PI / 180;
    double lat2 = p2.latitude * PI / 180;
    double lon2 = p2.longitude * PI / 180;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c;
    return d;
}

//Function to simulate GPS navigation given an array of GPS points
void simulate_navigation(GPS_Point* points, int num_points){
    int current_point_index = 0;
    GPS_Point current_point = points[current_point_index];
    printf("Starting navigation...\n");
    while(current_point_index != num_points-1){
        double distance_to_next_point = calculate_distance(current_point, points[current_point_index+1]);
        printf("\nCurrent point: (%lf, %lf)", current_point.latitude, current_point.longitude);
        printf("\nDistance to next point: %lf km\n", distance_to_next_point);
        if(distance_to_next_point < 1){
            //Reached next point, update current point
            current_point_index++;
            current_point = points[current_point_index];
            printf("Reached next point!\n");
        } else {
            //Move towards next point
            double bearing = atan2(sin(points[current_point_index+1].longitude-current_point.longitude)*cos(points[current_point_index+1].latitude),cos(current_point.latitude)*sin(points[current_point_index+1].latitude)-sin(current_point.latitude)*cos(points[current_point_index+1].latitude)*cos(points[current_point_index+1].longitude-current_point.longitude));
            double dist_diff = 1.0; //Simulate moving 1 km at a time
            double dlat = dist_diff * cos(bearing) / 111.0;
            double dlon = dist_diff * sin(bearing) / (111.0 * cos(current_point.latitude * PI / 180));
            current_point.latitude += dlat;
            current_point.longitude += dlon;
        }
    }
    printf("\nReached final destination: (%lf, %lf)\n", current_point.latitude, current_point.longitude);
}

int main(){
    //Array of GPS points to navigate through
    GPS_Point points[] = {{40.730610, -73.935242}, {51.509865, -0.118092}, {37.7749, -122.4194}, {-33.8688, 151.2093}, {-23.5505, -46.6333}};
    int num_points = 5;
    simulate_navigation(points, num_points);
    return 0;
}