//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECONDS_PER_DAY 86400

int main()
{
    srand(time(NULL)); // initialize random seed
    int days = 365.25 * 4.5; // number of days simulated
    int sun_x = 0, sun_y = 0; // coordinates of the sun
    int earth_x = 100, earth_y = 0; // coordinates of the earth
    float earth_speed = 29.78; // speed of the earth in km/s
    int mars_x = 228, mars_y = 0; // coordinates of mars
    float mars_speed = 24.08; // speed of mars in km/s
    
    // simulate the solar system
    for (int i = 1; i <= days; i++) {
        // calculate new position of earth
        float angle = (i * earth_speed) / SECONDS_PER_DAY;
        earth_x = 100 * cos(angle);
        earth_y = 100 * sin(angle);

        // calculate new position of mars
        angle = (i * mars_speed) / SECONDS_PER_DAY;
        mars_x = 228 * cos(angle);
        mars_y = 228 * sin(angle);

        // print the positions of the planets
        printf("Day %03d: Earth (%+06d,%+06d), Mars (%+06d,%+06d)\n",
               i, earth_x, earth_y, mars_x, mars_y);

        // randomly vary the position of the sun
        sun_x += rand() % 21 - 10;
        sun_y += rand() % 21 - 10;
    }

    // print the final positions of the planets
    printf("Final positions: Earth (%+06d,%+06d), Mars (%+06d,%+06d)\n",
           earth_x, earth_y, mars_x, mars_y);

    return 0;
}