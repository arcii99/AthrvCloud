//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMPERATURE 100 /* maximum temperature in Celsius */

/* function to generate a random temperature between 0 and MAX_TEMPERATURE */
double generate_temperature(void) {
    double temperature = (double)rand() / RAND_MAX; /* generate a random number between 0 and 1 */
    temperature *= MAX_TEMPERATURE; /* scale it to the maximum temperature */
    return temperature;
}

/* main function */
int main(void) {
    const int DAYS = 7; /* number of days in the simulation */
    const int HOURS = 24; /* number of hours in a day */
    double temperatures[DAYS][HOURS]; /* array to store temperatures for each day and hour */
    int i, j;

    /* initialize random seed */
    srand(time(NULL));

    /* generate temperatures for each day and hour */
    for (i = 0; i < DAYS; i++) {
        for (j = 0; j < HOURS; j++) {
            temperatures[i][j] = generate_temperature();
        }
    }

    /* print the temperatures for each day and hour */
    printf("Weather Simulation:\n\n");
    printf("Day | Hour | Temperature (C)\n");
    printf("----------------------------\n");
    for (i = 0; i < DAYS; i++) {
        for (j = 0; j < HOURS; j++) {
            printf("%d   | %02d   | %6.2f\n", i+1, j, temperatures[i][j]);
        }
        printf("----------------------------\n");
    }

    return 0;
}