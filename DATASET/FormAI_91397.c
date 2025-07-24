//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_TIME 5

int main()
{
    char command[BUFFER_SIZE], output[BUFFER_SIZE];
    double speed;
    int time_elapsed;

    printf("Welcome to the Internet Speed Test!\n\n");

    printf("Press Enter to start the test");
    fflush(stdin);
    getchar();

    printf("Testing...\n");

    clock_t start_time = clock();
    sprintf(command, "wget --output-document=/dev/null --quiet https://github.com/ >> /dev/null 2>&1");
    system(command);
    clock_t end_time = clock();

    time_elapsed = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;

    if (time_elapsed < MAX_TIME * 1000)
    {
        speed = 8 / ((double)time_elapsed / 1000);
        printf("Your internet speed is: %.2f Mbps\n", speed);
    }
    else
    {
        printf("The test took too long. Please make sure you are connected to the internet and try again.\n");
    }

    return 0;
}