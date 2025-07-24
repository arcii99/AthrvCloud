//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 10
#define MIN_LATITUDE 10.0
#define MAX_LATITUDE 30.0
#define MIN_LONGITUDE 70.0
#define MAX_LONGITUDE 90.0

typedef struct{
    char* name;
    float latitude;
    float longitude;
}City;

City cities[MAX_CITIES];

void initialize_cities(){
    srand(time(0));
    for(int i=0;i<MAX_CITIES;i++){
        cities[i].name = (char*)malloc(sizeof(char)*10);
        sprintf(cities[i].name, "City%d", i+1);
        cities[i].latitude = ((float)rand()/(float)(RAND_MAX))*(MAX_LATITUDE-MIN_LATITUDE)+MIN_LATITUDE;
        cities[i].longitude = ((float)rand()/(float)(RAND_MAX))*(MAX_LONGITUDE-MIN_LONGITUDE)+MIN_LONGITUDE;
    }
}

float calculate_distance(float lat1, float long1, float lat2, float long2){
    float pi = 3.14159265358979323846;
    float theta1 = lat1 * pi / 180.0;
    float theta2 = lat2 * pi / 180.0;
    float delta_theta = (lat2 - lat1) * pi / 180.0;
    float delta_lambda = (long2 - long1) * pi / 180.0;
    
    float a = sin(delta_theta/2) * sin(delta_theta/2) +
            cos(theta1) * cos(theta2) *
            sin(delta_lambda/2) * sin(delta_lambda/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = 6371 * c;
    return distance;
}

int main(){
    initialize_cities();
    float current_latitude = 20.0, current_longitude = 80.0;
    float total_distance = 0.0;
    printf("Starting GPS Navigation Simulation!\n\n");
    printf("Current Location: (%.2f,%.2f)\n",current_latitude,current_longitude);
    printf("Enter Destination City (1 to %d): ",MAX_CITIES);
    int destination;
    scanf("%d",&destination);
    destination--;
    printf("\n");
    while(destination >=0 && destination < MAX_CITIES){
        printf("Destination : %s (%.2f,%.2f)\n",cities[destination].name,cities[destination].latitude,cities[destination].longitude);
        printf("Route: %s", cities[destination].name);
        float distance = calculate_distance(current_latitude,current_longitude,cities[destination].latitude,cities[destination].longitude);
        printf(" (%.2f km)",distance);
        total_distance += distance;
        current_latitude = cities[destination].latitude;
        current_longitude = cities[destination].longitude;
        printf("\n\n");
        printf("Current Location: (%.2f,%.2f)\n",current_latitude,current_longitude);
        printf("Enter Destination City (1 to %d) or -1 to exit: ",MAX_CITIES);
        scanf("%d",&destination);
        destination--;
        printf("\n");
    }
    printf("Total Distance Travelled: %.2f km",total_distance);
    printf("\n\nEnd of GPS Navigation Simulation!");
    return 0;
}