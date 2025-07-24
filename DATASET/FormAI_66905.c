//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int i;
    double sum = 0;
    double average = 0;
    double variance = 0;
    double deviation = 0;
    double temp[365];

    // Generate random temperatures for one year
    srand(time(NULL)); // Use current time as seed for random generator
    for (i = 0; i < 365; i++) {
        temp[i] = ((double)rand() / (double)RAND_MAX) * 40 + 10; // Random temperature between 10 and 50 degrees Celsius
        sum += temp[i];
    }

    // Calculate average temperature
    average = sum / 365;

    // Calculate variance
    for (i = 0; i < 365; i++) {
        variance += (temp[i] - average) * (temp[i] - average);
    }
    variance /= 365;

    // Calculate standard deviation
    deviation = sqrt(variance);

    // Print statistics
    printf("Average temperature: %.2lf C\n", average);
    printf("Variance: %.2lf C^2\n", variance);
    printf("Standard deviation: %.2lf C\n", deviation);

    // Check if it was a hot year or a cold year
    if (average > 25) {
        printf("It was a hot year!\n");
    } else if (average < 15) {
        printf("It was a cold year!\n");
    } else {
        printf("It was a moderate year!\n");
    }

    // Check if there were extreme temperatures (above 40 or below 0)
    for (i = 0; i < 365; i++) {
        if (temp[i] > 40) {
            printf("Extreme temperature found on day %d: %.2lf C\n", i+1, temp[i]);
        } else if (temp[i] < 0) {
            printf("Extreme temperature found on day %d: %.2lf C\n", i+1, temp[i]);
        }
    }

    return 0;
}