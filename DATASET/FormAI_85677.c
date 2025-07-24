//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char output[1024];
    FILE *fp; 
    int totalMemory, freeMemory;

    while (1)
    {
        fp = popen("free -t -m | grep Total", "r");
        fgets(output, sizeof(output)-1, fp);
        pclose(fp);
        sscanf(output, "Total: %d %*s %d %*s %d %*s", &totalMemory, &freeMemory);

        printf("Total memory: %dMB, Free memory: %dMB, Used memory: %dMB\n",
               totalMemory, freeMemory, totalMemory - freeMemory);

        sleep(1);
    }
    return 0;
}