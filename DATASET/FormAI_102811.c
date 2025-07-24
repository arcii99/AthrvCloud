//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1048576          // 1 MB in bytes

int main()
{
    long long usage = 0;    // variable to store RAM usage
    const long long total = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE); // total RAM in bytes

    while (1)
    {
        FILE* fp = fopen("/proc/self/status", "r"); // open the status file of the current process
        char line[128];

        while (fgets(line, 128, fp) != NULL)
        {
            if (strncmp(line, "VmRSS:", 6) == 0) {  // get the line containing VmRSS (resident set size) 
                usage = atoi(line+7)*1024;          // convert the value to bytes
                break;
            }
        }
        fclose(fp);

        printf("RAM usage: %lld MB / %lld MB\n", usage/MB, total/MB);
        sleep(1);   // wait for 1 second
    }

    return 0;
}