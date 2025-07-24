//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int latency = 0, drops = 0, jitter = 0, throughput = 0;

    while(1)
    {
        // Simulating network data
        latency = rand() % 100 + 1;
        drops = rand() % 10 + 1;
        jitter = rand() % 50 + 1;
        throughput = rand() % 1000 + 1;

        // Check latency
        if(latency >= 50)
        {
            printf("Latency is too high! Current value is %d\n", latency);
        }

        // Check drops
        if(drops >= 5)
        {
            printf("Drops are too high! Current value is %d\n", drops);
        }

        // Check jitter
        if(jitter >= 25)
        {
            printf("Jitter is too high! Current value is %d\n", jitter);
        }

        // Check throughput
        if(throughput <= 500)
        {
            printf("Throughput is too low! Current value is %d\n", throughput);
        }

        // Wait for 10 seconds before checking again
        sleep(10);
    }

    return 0;
}