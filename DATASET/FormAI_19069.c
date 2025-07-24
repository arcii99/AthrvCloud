//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getSpeed();
void measureSpeed();

int main()
{
    measureSpeed();
    return 0;
}

void measureSpeed()
{
    double timeTaken;
    double speed;

    printf("Measuring internet speed...\n");

    clock_t start_time = clock();
    speed = getSpeed();
    clock_t end_time = clock();

    timeTaken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Your internet speed is: %.2f Mbps\n", speed);
    printf("Time taken: %.2f seconds\n", timeTaken);
}

double getSpeed()
{
    double speed = rand() % 101; // Generating random speed between 0 to 100 Mbps
    return speed;
}