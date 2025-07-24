//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speeds[10];
    int i;
    double total_speed = 0.0;
    srand(time(NULL));

    printf("Running internet speed test...\n\n");

    for (i = 0; i < 10; i++) {
        speeds[i] = rand() % 100;
        printf("Speed test %d: %d Mbps\n", i+1, speeds[i]);
        total_speed += speeds[i];
    }

    double avg_speed = total_speed / 10.0;

    printf("\n\nAverage internet speed: %.2f Mbps\n", avg_speed);

    return 0;
}