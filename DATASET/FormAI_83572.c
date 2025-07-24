//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    FILE *fp;
    char path[1035], mem[6], unit[3], cmd[200], pct[6];
    int tot, used, free, buffers, cached;

    while (1)
    {
        strcpy(cmd, "cat /proc/meminfo | awk '/MemTotal/{printf \"Total: %s\",$2;}'");
        fp = popen(cmd, "r");

        if (fp == NULL)
        {
            printf("Failed to run command\n");
            exit(1);
        }

        /* Read the output a line at a time - buffer size is 1034*/
        while (fgets(path, sizeof(path) - 1, fp) != NULL)
        {
            printf("%s", path);
        }
        /* close */
        pclose(fp);

        strcpy(cmd, "cat /proc/meminfo | awk '/MemFree/{printf \"Free: %s\",$2;}'");
        fp = popen(cmd, "r");

        if (fp == NULL)
        {
            printf("Failed to run command\n");
            exit(1);
        }

        /* Read the output a line at a time - buffer size is 1034*/
        while (fgets(path, sizeof(path) - 1, fp) != NULL)
        {
            printf("%s", path);
            sscanf(path, "Free: %d %s", &free, unit);
            if (strcmp(unit, "kB") == 0)
            {
                free = free * 1024;
            }
        }
        /* close */
        pclose(fp);

        strcpy(cmd, "cat /proc/meminfo | awk '/Buffers/{printf \"Buffers: %s\",$2;}'");
        fp = popen(cmd, "r");

        if (fp == NULL)
        {
            printf("Failed to run command\n");
            exit(1);
        }

        /* Read the output a line at a time - buffer size is 1034*/
        while (fgets(path, sizeof(path) - 1, fp) != NULL)
        {
            printf("%s", path);
            sscanf(path, "Buffers: %d %s", &buffers, unit);
            if (strcmp(unit, "kB") == 0)
            {
                buffers = buffers * 1024;
            }
        }
        /* close */
        pclose(fp);

        strcpy(cmd, "cat /proc/meminfo | awk '/Cached/{printf \"Cached: %s\",$2;}'");
        fp = popen(cmd, "r");

        if (fp == NULL)
        {
            printf("Failed to run command\n");
            exit(1);
        }

        /* Read the output a line at a time - buffer size is 1034*/
        while (fgets(path, sizeof(path) - 1, fp) != NULL)
        {
            printf("%s", path);
            sscanf(path, "Cached: %d %s", &cached, unit);
            if (strcmp(unit, "kB") == 0)
            {
                cached = cached * 1024;
            }
        }
        /* close */
        pclose(fp);

        tot = free + buffers + cached;

        used = atoi(path) - tot;

        sprintf(mem, "%d", used / 1024); // Current RAM usage in MB

        printf("\nCurrent RAM usage: %s MB\n", mem);

        printf("------------------------------\n");

        //Refresh the Memory usage every 5 seconds
        sleep(5);
    }
    return 0;
}