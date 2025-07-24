//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    float tempC;
    int i;
    time_t t;

    // initialize random seed
    srand((unsigned) time(&t));

    // generate 50 random temperature readings between -10 and 30 degrees Celsius
    for(i = 0; i < 50; i++) 
    {
        tempC = (float)rand()/(float)(RAND_MAX/40)-10;
        printf("Temperature reading %d: %.1f degrees Celsius\n", i+1, tempC);
    }

    return 0;
}