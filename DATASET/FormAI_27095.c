//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double internet_speed(double [], int);

int main()
{
    double internet_speeds[10];
    int i;

    printf("Please wait while we test your internet speed...\n");

    // Generate 10 random internet speeds between 0 and 100 Mbps
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        internet_speeds[i] = (double)rand()/(double)(RAND_MAX/100);
    }

    // Calculate the average internet speed
    double avg_speed = internet_speed(internet_speeds, 10);

    printf("Your average internet speed is %.2lf Mbps\n", avg_speed);

    if (avg_speed < 50) {
        printf("Your internet speed is too slow. Please contact your service provider.\n");
    } else if (avg_speed < 100) {
        printf("Your internet speed is good, but there is room for improvement.\n");
    } else {
        printf("Your internet speed is excellent! Keep up the good work!\n");
    }

    return 0;
}

double internet_speed(double arr[], int size) {
    double sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}