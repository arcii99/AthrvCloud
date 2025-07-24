//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: artistic
//C Drone Remote Control: An Artistic Approach

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FlightMenu(void);
void FlyDrone(int, int);
void HandleSignal(void);
void Disconnect(void);

bool IsConnected = false;
int LeftThrottle = 0;
int RightThrottle = 0;

int main()
{
    char sInput;
    int iCommand;
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Please connect to your drone. Press 'c' to connect.\n");
    sInput = getchar();
    if (sInput == 'c')
    {
        IsConnected = true;
        printf("You are now connected to your drone. \n");
    }
    else
    {
        printf("Could not connect to your drone. Please try again later.\n");
        return 0;
    }
    
    while (IsConnected)
    {
        FlightMenu();
        sInput = getchar();
        iCommand = sInput - '0';
        switch (iCommand)
        {
            case 1:
                FlyDrone(-1,1);
                break;
            case 2:
                FlyDrone(-1,0);
                break;
            case 3:
                FlyDrone(-1,-1);
                break;
            case 4:
                FlyDrone(0,1);
                break;
            case 5:
                printf("Your drone has landed successfully. \n");
                break;
            case 6:
                FlyDrone(0,-1);
                break;
            case 7:
                FlyDrone(1,1);
                break;
            case 8:
                FlyDrone(1,0);
                break;
            case 9:
                FlyDrone(1,-1);
                break;
            case 0:
                Disconnect();
                break;
            default:
                printf("Invalid command entered. Please try again.\n");
                break;
        }
    }
    printf("You have disconnected from your drone. Thank you for using C Drone Remote Control! \n");
    return 0;
}

void FlightMenu()
{
    printf("\n");
    printf("Please choose a command to fly your drone:\n\n");
    printf("1. Fly up & right     2. Fly up    3. Fly up & left\n\n");
    printf("4. Fly right          5. Land     6. Fly left\n\n");
    printf("7. Fly down & right   8. Fly down 9. Fly down & left\n\n");
    printf("0. Disconnect\n");
}

void FlyDrone(int Left, int Right)
{
    LeftThrottle += Left;
    RightThrottle += Right;
    printf("Your drone is flying at LeftThrottle = %d and RightThrottle = %d\n", LeftThrottle, RightThrottle);
    HandleSignal();
}

void HandleSignal()
{
    if ((LeftThrottle == 0) && (RightThrottle == 0))
    {
        printf("Your drone is hovering at its current height. \n");
    }
    else if ((LeftThrottle >= RightThrottle) && (LeftThrottle > 0))
    {
        printf("Your drone is flying higher. \n");
    }
    else if ((LeftThrottle <= RightThrottle) && (RightThrottle > 0))
    {
        printf("Your drone is flying higher. \n");
    }
    else if ((LeftThrottle >= RightThrottle) && (LeftThrottle < 0))
    {
        printf("Your drone is flying lower. \n");
    }
    else if ((LeftThrottle <= RightThrottle) && (RightThrottle < 0))
    {
        printf("Your drone is flying lower. \n");
    }
}

void Disconnect()
{
    IsConnected = false;
    printf("You have disconnected from your drone. Thank you for using C Drone Remote Control! \n");
}