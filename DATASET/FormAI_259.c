//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_DEVICES 100
#define MAX_THREADS 50

struct device_info
{
    char name[20];
    char ip[20];
};

struct device_info devices[MAX_DEVICES];
int num_devices = 0;

void* ping_thread(void* arg)
{
    int i, j;
    char cmd[100];
    char result[100];

    for(i = 0; i < num_devices; i++)
    {
        sprintf(cmd, "ping -c 1 %s > /dev/null", devices[i].ip);
        if(system(cmd) == 0)
        {
            printf("%s (%s) is up\n", devices[i].name, devices[i].ip);
            for(j = 0; j < num_devices; j++)
            {
                if(i != j)
                {
                    sprintf(cmd, "ping -c 1 -w 1 %s > /dev/null", devices[j].ip);
                    if(system(cmd) == 0)
                    {
                        sprintf(result, "%s is directly connected to %s", devices[j].name, devices[i].name);
                        printf("%s\n", result);
                    }
                }
            }
        }
    }

    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[MAX_THREADS];

    strcpy(devices[num_devices].name, "Router 1");
    strcpy(devices[num_devices].ip, "192.168.1.1");
    num_devices++;

    strcpy(devices[num_devices].name, "Switch 1");
    strcpy(devices[num_devices].ip, "192.168.1.2");
    num_devices++;

    strcpy(devices[num_devices].name, "PC 1");
    strcpy(devices[num_devices].ip, "192.168.1.3");
    num_devices++;

    strcpy(devices[num_devices].name, "PC 2");
    strcpy(devices[num_devices].ip, "192.168.1.4");
    num_devices++;

    strcpy(devices[num_devices].name, "Printer 1");
    strcpy(devices[num_devices].ip, "192.168.1.5");
    num_devices++;

    pthread_create(&threads[0], NULL, ping_thread, NULL);
    pthread_join(threads[0], NULL);

    return 0;
}