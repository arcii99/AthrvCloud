//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option, speed = 0, altitude = 0;
    int *remoteControl;
    
    remoteControl = (int *) malloc(sizeof(int));
    
    printf("\nWelcome to C Drone Remote Control\n\n");
    
    do
    {
        printf("Choose an option below:\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Increase Altitude\n");
        printf("4. Decrease Altitude\n");
        printf("5. Quit\n");
        printf("\nEnter your option here: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                
                printf("\nCurrent Speed: %d\n", speed);
                increaseSpeed(&speed, remoteControl);
                printf("New Speed: %d\n\n", speed);
                
                break;
                
            case 2:
                
                printf("\nCurrent Speed: %d\n", speed);
                decreaseSpeed(&speed, remoteControl);
                printf("New Speed: %d\n\n", speed);
                
                break;
                
            case 3:
                
                printf("\nCurrent Altitude: %d\n", altitude);
                increaseAltitude(&altitude, remoteControl);
                printf("New Altitude: %d\n\n", altitude);
                
                break;
                
            case 4:
                
                printf("\nCurrent Altitude: %d\n", altitude);
                decreaseAltitude(&altitude, remoteControl);
                printf("New Altitude: %d\n\n", altitude);
                
                break;
                
            case 5:
                
                printf("\nExiting Program...\n\n");
                
                break;
                
            default:
                
                printf("\nInvalid option! Please select between 1-5.\n\n");
                
                break;
        }
        
    } while (option != 5);
    
    free(remoteControl);
    
    return 0;
}

void increaseSpeed(int *speed, int *remoteControl)
{
    if (*speed >= 100)
    {
        printf("Maximum speed is 100. Cannot increase further.\n");
    }
    else
    {
        (*speed)++;
        
        if (*speed >= 50 && *remoteControl == 0)
        {
            printf("Speed reached 50. Activating remote control to maintain altitude.\n");
            activateRemoteControl(remoteControl);
        }
    }
    
    if (*remoteControl == 1)
    {
        maintainAltitude(speed, remoteControl);
    }
}

void decreaseSpeed(int *speed, int *remoteControl)
{
    if (*speed <= 0)
    {
        printf("Minimum speed is 0. Cannot decrease further.\n");
    }
    else
    {
        (*speed)--;
        
        if (*speed < 50 && *remoteControl == 1)
        {
            printf("Speed fell below 50. Deactivating remote control to manual control.\n");
            deactivateRemoteControl(remoteControl);
        }
    }
    
    if (*remoteControl == 1)
    {
        maintainAltitude(speed, remoteControl);
    }
}

void increaseAltitude(int *altitude, int *remoteControl)
{
    if (*altitude >= 50)
    {
        printf("Maximum altitude is 50. Cannot increase further.\n");
    }
    else
    {
        (*altitude)++;
        
        if (*altitude >= 25 && *remoteControl == 0)
        {
            printf("Altitude reached 25. Activating remote control to maintain altitude.\n");
            activateRemoteControl(remoteControl);
        }
    }
    
    if (*remoteControl == 1)
    {
        maintainAltitude(altitude, remoteControl);
    }
}

void decreaseAltitude(int *altitude, int *remoteControl)
{
    if (*altitude <= 0)
    {
        printf("Minimum altitude is 0. Cannot decrease further.\n");
    }
    else
    {
        (*altitude)--;
        
        if (*altitude < 25 && *remoteControl == 1)
        {
            printf("Altitude fell below 25. Deactivating remote control to manual control.\n");
            deactivateRemoteControl(remoteControl);
        }
    }
    
    if (*remoteControl == 1)
    {
        maintainAltitude(altitude, remoteControl);
    }
}

void activateRemoteControl(int *remoteControl)
{
    (*remoteControl) = 1;
    printf("Remote Control activated.\n");
}

void deactivateRemoteControl(int *remoteControl)
{
    (*remoteControl) = 0;
    printf("Remote Control deactivated.\n");
}

void maintainAltitude(int *value, int *remoteControl)
{
    printf("Maintaining altitude...\n");
    increaseSpeed(value, remoteControl);
    decreaseSpeed(value, remoteControl);
    increaseAltitude(value, remoteControl);
    decreaseAltitude(value, remoteControl);
}