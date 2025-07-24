//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTALCITIES 5
#define MAXDISTANCE 100

typedef struct {
    int x;
    int y;
} City;

City cities[TOTALCITIES];

void generateCities() {
    for(int i=0; i<TOTALCITIES; i++) {
        cities[i].x = rand() % MAXDISTANCE;
        cities[i].y = rand() % MAXDISTANCE;
    }
}

void printCities() {
    for(int i=0; i<TOTALCITIES; i++) {
        printf("%d. (%d, %d)\n", i+1, cities[i].x, cities[i].y);
    }
}

float distance(City a, City b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void navigation(int startCity, int endCity) {
    City currentCity = cities[startCity-1];
    City targetCity = cities[endCity-1];
    float totalDistance = 0.0;

    printf("Navigation started.\n");
    printf("Current Location: City %d (%d,%d)\n", startCity, currentCity.x, currentCity.y);
    printf("Target Location: City %d (%d,%d)\n", endCity, targetCity.x, targetCity.y);

    while(currentCity.x != targetCity.x && currentCity.y != targetCity.y) {
        float minDistance = MAXDISTANCE+1;
        int nextCity = -1;
        for(int i=0; i<TOTALCITIES; i++) {
            if(i+1 == startCity) {
                continue;
            }
            if(i+1 == endCity) {
                continue;
            }
            float d = distance(currentCity, cities[i]);
            if(d < minDistance) {
                minDistance = d;
                nextCity = i+1;
            }
        }
        if(nextCity == -1) {
            printf("Cannot reach target location.\n");
            return;
        }
        totalDistance += minDistance;
        currentCity = cities[nextCity-1];
        printf("Move to City %d. Distance: %.2f. Total Distance: %.2f\n", nextCity, minDistance, totalDistance);
    }

    float d = distance(currentCity, targetCity);
    totalDistance += d;
    printf("Target location reached. Distance: %.2f. Total Distance: %.2f\n", d, totalDistance);
    printf("Navigation ended.\n");
}

int main() {
    srand(time(NULL));
    generateCities();
    printCities();

    navigation(rand() % TOTALCITIES + 1, rand() % TOTALCITIES + 1);

    return 0;
}