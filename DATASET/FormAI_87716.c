//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    long int pmem_size = 0, vmem_size = 0;
    int size = 0;
    char line[256];
    FILE *fp;

    printf("C RAM Usage Monitor\n");

    while (1)
    {
        // get process id of current process
        pid = getpid();

        // open the status file of process
        sprintf(line, "/proc/%d/status", pid);
        fp = fopen(line, "r");

        // read the status file line by line
        while (fgets(line, sizeof(line), fp))
        {
            if (sscanf(line, "VmSize: %d kB", &size) == 1) // get virtual memory size
            {
                vmem_size = size * 1000L;
            }
            if (sscanf(line, "VmRSS: %d kB", &size) == 1) // get physical memory size
            {
                pmem_size = size * 1000L;
            }
        }

        // close the file pointer
        fclose(fp);

        // print the memory usage
        printf("Physical Memory Usage: %ld Bytes\n", pmem_size);
        printf("Virtual Memory Usage: %ld Bytes\n", vmem_size);

        // sleep for 1 second
        sleep(1);
    }

    return 0;
}