//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_WAIT_TIME 10

int testSpeed(char* server)
{
    char command[BUFFER_SIZE] = {0};
    strcat(command, "ping -c 10 ");
    strcat(command, server);

    FILE *pipe = popen(command, "r");
    if (!pipe)
    {
        printf("Error: failed to open pipe.\n");
        return -1;
    }

    char output[BUFFER_SIZE] = {0};
    while (fgets(output, BUFFER_SIZE, pipe) != NULL)
    {
        if (strstr(output, "rtt min/avg/max/mdev") != NULL)
        {
            int i = 0;
            char *token = strtok(output, "/");
            while (token != NULL)
            {
                if (i == 4)
                {
                    pclose(pipe);
                    return (int) (atof(token) * 1000);
                }
                i++;
                token = strtok(NULL, "/");
            }
            break;
        }
    }
    pclose(pipe);
    return -1;
}

int main()
{
    printf("Starting internet speed test...\n\n");
    printf("Testing download speed...\n");

    int downloadSpeed = -1;
    int timeElapsed = 0;
    while (downloadSpeed == -1 && timeElapsed < MAX_WAIT_TIME)
    {
        downloadSpeed = testSpeed("download.example.com");
        timeElapsed++;
        sleep(1);
    }

    if (downloadSpeed == -1)
    {
        printf("Failed to get download speed.\n");
    }
    else
    {
        printf("Download speed is %d ms.\n", downloadSpeed);
    }

    printf("\nTesting upload speed...\n");

    int uploadSpeed = -1;
    timeElapsed = 0;
    while (uploadSpeed == -1 && timeElapsed < MAX_WAIT_TIME)
    {
        uploadSpeed = testSpeed("upload.example.com");
        timeElapsed++;
        sleep(1);
    }

    if (uploadSpeed == -1)
    {
        printf("Failed to get upload speed.\n");
    }
    else
    {
        printf("Upload speed is %d ms.\n", uploadSpeed);
    }

    printf("\nInternet speed test complete.\n");
    return 0;
}