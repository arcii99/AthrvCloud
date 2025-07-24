//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_PLANETS 10
#define DISTANCE_MAX 1000

struct planet {
    char name[20];
    int x;
    int y;
};

void generate_planets(struct planet* planets) {
    int i;
    for(i = 0; i < NUM_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].x = rand() % DISTANCE_MAX;
        planets[i].y = rand() % DISTANCE_MAX;
    }
}

double calculate_distance(struct planet planet1, struct planet planet2) {
    int x_diff = abs(planet1.x - planet2.x);
    int y_diff = abs(planet1.y - planet2.y);
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    return distance;
}

int main(){
    struct planet planets[NUM_PLANETS];
    int i, j;
    srand(time(NULL)); // seed the random number generator
    
    // Generate planets with random coordinates
    generate_planets(planets);
    
    // Print out planet coordinates
    for(i = 0; i < NUM_PLANETS; i++) {
        printf("%s is located at (%d, %d)\n", planets[i].name, planets[i].x, planets[i].y);
    }
    
    // Calculate distance between each pair of planets
    for(i = 0; i < NUM_PLANETS; i++) {
        for(j = i+1; j < NUM_PLANETS; j++) {
            double distance = calculate_distance(planets[i], planets[j]);
            printf("The distance between %s and %s is %lf\n", planets[i].name, 
                   planets[j].name, distance);
        }
    }
    
    return 0;
}