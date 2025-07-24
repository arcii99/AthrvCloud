//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char command[20], device[20], status[20], timer[20];
    time_t current_time;
    struct tm *local_time;

    printf("Welcome to your Smart Home Automation System!\n\n");

    while(1)
    {
        printf(">>");
        scanf("%s %s", command, device);

        if(strcmp(command, "turn") == 0)
        {
            scanf("%s", status);
            printf("%s has been turned %s.\n\n", device, status);
        }
        else if(strcmp(command, "set") == 0)
        {
            scanf("%s", timer);
            current_time = time(NULL);
            local_time = localtime(&current_time);
            printf("Your %s will be turned on in %s seconds at %02d:%02d:%02d.\n\n", device, timer, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
        }
        else if(strcmp(command, "exit") == 0)
        {
            printf("Thank you for using your Smart Home Automation System!\n\n");
            break;
        }
        else
        {
            printf("Invalid command. Please try again.\n\n");
        }
    }
    
    return 0;
}