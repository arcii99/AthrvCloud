//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include<stdio.h>
#include<math.h> 
#include<stdlib.h> 
#include<string.h>
#include<time.h> 

#define PI 3.1415926535 

int main() 
{
    char lat_dir[2], long_dir[2]; 
    double lat1, long1, lat2, long2; 
    double d, r, theta, alpha; 
    int start_time, end_time; 

    // Random starting point
    printf("Welcome to the Surrealist GPS Navigation Simulation!\n");
    printf("Acquiring your current coordinates...\n");
    srand(time(0));
    lat1 = (double)rand() * 90.0 / RAND_MAX;
    long1 = (double)rand() * 180.0 / RAND_MAX;
    strcpy(lat_dir, lat1 >= 0 ? "N" : "S");
    strcpy(long_dir, long1 >= 0 ? "E" : "W");
    lat1 = fabs(lat1);
    long1 = fabs(long1);
    printf("Current Location: %.6f %s, %.6f %s\n", lat1, lat_dir, long1, long_dir);

    // Prompt for destination
    printf("Please enter the coordinates of your destination:\n");
    printf("Latitude (decimal): ");
    scanf("%lf", &lat2);
    printf("Longitude (decimal): ");
    scanf("%lf", &long2);
    strcpy(lat_dir, lat2 >= 0 ? "N" : "S");
    strcpy(long_dir, long2 >= 0 ? "E" : "W");
    lat2 = fabs(lat2);
    long2 = fabs(long2);
    printf("Destination: %.6f %s, %.6f %s\n", lat2, lat_dir, long2, long_dir);

    // Calculate distance and direction
    d = 2 * asin(sqrt(pow(sin((lat1 - lat2) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long1 - long2) / 2), 2)));
    r = 6371.0; // radius of Earth in km
    d = d * r;
    theta = atan2(sin(long1 - long2) * cos(lat2), cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(long1 - long2));
    alpha = fmod((theta + 2 * PI), (2 * PI));
    alpha = alpha * 180.0 / PI;
    printf("Distance to Destination: %.2f km\n", d);
    printf("Direction to Destination: %.2f degrees %s of due %s\n", fabs(alpha), alpha > 0 ? "east" : "west", lat1 > lat2 ? "north" : "south");

    // Simulate navigation
    start_time = time(0);
    printf("Navigation will commence in 3 seconds.\n");
    for(int i = 3; i >= 1; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("Commencing navigation.\n");
    double lat = lat1, longt = long1;
    double prev_d = d + 1.0, curr_d = d;
    while(curr_d >= prev_d)
    {
        lat = lat + (lat2 - lat1) / d;
        longt = longt + (long2 - long1) / d;
        d = 2 * asin(sqrt(pow(sin((lat - lat2) / 2), 2) + cos(lat) * cos(lat2) * pow(sin((longt - long2) / 2), 2)));
        d = d * r;
        prev_d = curr_d;
        curr_d = d;
        printf("Distance to Destination: %.2f km\n", d);
        printf("Current Location: %.6f %s, %.6f %s\n", lat, lat > 0 ? "N" : "S", longt, longt > 0 ? "E" : "W");
        sleep(1);
    }
    printf("You have arrived at your destination.\n");
    end_time = time(0);
    printf("Total time taken: %d seconds.\n", end_time - start_time);

    return 0;
}