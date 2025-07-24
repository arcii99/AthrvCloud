//FormAI DATASET v1.0 Category: Fractal Generation ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// function prototype
bool test(double x, double y);

int main() {
    srand(time(NULL));  // seed the random number generator with current time

    double x, y;    // coordinates
    int i, count = 0;   // loop counter and point counter
    int max_points = 500000;    // max number of points to generate
    double pi_estimate; // estimate value of pi

    for (i = 0; i < max_points; i++) {
        x = ((double)rand() / RAND_MAX) * 2 - 1;  // generate a random x-coordinate between -1 and 1
        y = ((double)rand() / RAND_MAX) * 2 - 1;  // generate a random y-coordinate between -1 and 1

        if (test(x, y)) {   // if the point is inside the unit circle
            count++;    // increment point counter
        }
    }

    pi_estimate = (double)count / max_points * 4;   // calculate estimated value of pi
    
    printf("Estimated value of pi is %.6f.\n", pi_estimate);

    return 0;
}

bool test(double x, double y) {
    double r = sqrt(pow(x, 2) + pow(y, 2));   // calculate the distance from the origin to the point

    if (r <= 1) {   // if the distance is less than or equal to 1
        return true;    // the point is inside the unit circle
    } else {
        return false;   // the point is outside the unit circle
    }
}