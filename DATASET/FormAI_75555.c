//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STR 100

typedef struct {
    float lat;
    float longi;
}coordinates;

void inputDest(coordinates *destination);
void inputCurrent(coordinates *current);
float distance(coordinates destination, coordinates current);
void startNavigation(coordinates destination, coordinates current);

int main() {
    coordinates destination, current;

    printf("Welcome to GPS Navigation Simulation\n\n");
    printf("Please enter destination coordinates:\n");
    inputDest(&destination);

    printf("Please enter current coordinates:\n");
    inputCurrent(&current);

    printf("\nCalculating distance to destination...\n\n");

    float dist = distance(destination, current);
    printf("Distance to destination: %.2f km\n\n", dist);

    if(dist > 1) {
        startNavigation(destination, current);
    } else {
        printf("You have arrived at your destination\n");
    }

    return 0;
}

void inputDest(coordinates *destination) {
    printf("Enter destination latitude: ");
    scanf("%f", &destination->lat);
    printf("Enter destination longitude: ");
    scanf("%f", &destination->longi);
    printf("\n");
}

void inputCurrent(coordinates *current) {
    printf("Enter current latitude: ");
    scanf("%f", &current->lat);
    printf("Enter current longitude: ");
    scanf("%f", &current->longi);
    printf("\n");
}

float distance(coordinates destination, coordinates current) {
    float dist = 0;
    float x1 = destination.lat;
    float y1 = destination.longi;
    float x2 = current.lat;
    float y2 = current.longi;

    dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return dist;
}

void startNavigation(coordinates destination, coordinates current) {
    float dist = distance(destination, current);
    float prevDist = dist;

    while(dist > 0.1) {
        printf("Distance to destination: %.2f km\n\n", dist);
        printf("Enter your next move (North/South/East/West): ");
        char move[MAX_STR];
        scanf("%s", move);

        if(strcmp(move, "North") == 0) {
            current.lat += 0.001;
        } else if(strcmp(move, "South") == 0) {
            current.lat -= 0.001;
        } else if(strcmp(move, "East") == 0) {
            current.longi += 0.001;
        } else if(strcmp(move, "West") == 0) {
            current.longi -= 0.001;
        } else {
            printf("Invalid move entered. Please try again\n");
            continue;
        }

        prevDist = dist;
        dist = distance(destination, current);

        if(dist >= prevDist) {
            printf("You are moving away from the destination. Please turn around.\n\n");
            dist = prevDist;
            current.lat -= (current.lat - destination.lat) / 2;
            current.longi -= (current.longi - destination.longi) / 2;
        } else {
            printf("Your current coordinates: (%f, %f)\n\n", current.lat, current.longi);
        }

        printf("-----------------------------------------------------");
    }

    printf("You have arrived at your destination\n");
}