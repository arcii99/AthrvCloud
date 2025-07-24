//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROUTERS 10
#define MAX_DELAY 100

int main()
{
    srand(time(NULL));
    int router[NUM_ROUTERS] = {0};
    int total_delay = 0;

    printf("Initializing network...\n");

    // simulate network traffic and delay between routers
    for (int i = 0; i < NUM_ROUTERS; i++)
    {
        for (int j = i + 1; j < NUM_ROUTERS; j++)
        {
            int delay = rand() % MAX_DELAY + 1;
            total_delay += delay;
            router[i] += delay;
            router[j] += delay;
        }
    }

    printf("Total network traffic delay: %d ms\n", total_delay);

    // calculate average delay per router
    float avg_delay = (float)total_delay / ((NUM_ROUTERS * (NUM_ROUTERS - 1)) / 2);
    printf("Average delay per router: %.2f ms\n", avg_delay);

    // monitor network quality of service
    printf("Monitoring network quality of service...\n");
    for (int i = 0; i < NUM_ROUTERS; i++)
    {
        if (router[i] > (avg_delay * 2))
        {
            printf("Router %d is experiencing high network delay! Alerting administrator...\n", i);
        }
        else
        {
            printf("Router %d is operating within acceptable network delay range.\n", i);
        }
    }

    return 0;
}