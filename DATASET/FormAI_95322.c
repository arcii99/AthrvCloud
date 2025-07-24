//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void redLight();
void yellowLight();
void greenLight();

int main()
{
    time_t start_t, end_t;
    double diff_t;

    time(&start_t);
    printf("Starting the traffic light controller...\n");

    int i = 0;

    while (i < 10)
    {
        printf("\nTraffic light is RED\n");
        redLight();
        printf("\nTraffic light is YELLOW\n");
        yellowLight();
        printf("\nTraffic light is GREEN\n");
        greenLight();

        i++;
    }

    time(&end_t);
    diff_t = difftime(end_t, start_t);

    printf("\nTotal time to run traffic light controller: %.2lf seconds\n", diff_t);

    return 0;
}

void redLight()
{
    printf("STOP! All vehicles must come to a complete stop.\n");

    // wait for 10 seconds
    int wait = 10;
    while (wait > 0)
    {
        printf("%d seconds remaining...\n", wait);
        wait--;
        sleep(1);
    }
}

void yellowLight()
{
    printf("Caution! Vehicles should slow down and be prepared to stop.\n");

    // wait for 3 seconds
    int wait = 3;
    while (wait > 0)
    {
        printf("%d seconds remaining...\n", wait);
        wait--;
        sleep(1);
    }
}

void greenLight()
{
    printf("Go! All vehicles may proceed through the intersection.\n");

    // wait for 15 seconds
    int wait = 15;
    while (wait > 0)
    {
        printf("%d seconds remaining...\n", wait);
        wait--;
        sleep(1);
    }
}