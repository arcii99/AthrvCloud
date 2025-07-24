//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    double loadavg[3];

    while (1) {
        if (getloadavg(loadavg, 3) == -1) {
            perror("getloadavg");
            exit(EXIT_FAILURE);
        }

        // Print CPU usage statistics
        printf("CPU Usage: %f %%\n", (loadavg[0] / sysconf(_SC_NPROCESSORS_ONLN)) * 100);

        sleep(1); // Wait for 1 seconds
    }

    return 0;
}