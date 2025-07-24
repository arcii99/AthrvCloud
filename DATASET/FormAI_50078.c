//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>  
#include <string.h> 

int main()
{
    int light1Status = 0;
    int light2Status = 0;
    int fanStatus = 0;
    int temp = 25; // temperature in Celsius
    int humidity = 50; // humidity level in percentage
    
    while(1) // infinite loop for continuous operation
    {
        // user options
        printf("Enter choice:\n");
        printf("1. Turn on/off Light 1\n");
        printf("2. Turn on/off Light 2\n");
        printf("3. Turn on/off Fan\n");
        printf("4. Increase temperature\n");
        printf("5. Decrease temperature\n");
        printf("6. Increase humidity\n");
        printf("7. Decrease humidity\n");

        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(light1Status == 0)
                {
                    printf("Turning on Light 1...\n");
                    light1Status = 1;
                }
                else
                {
                    printf("Turning off Light 1...\n");
                    light1Status = 0;
                }
                break;
            case 2:
                if(light2Status == 0)
                {
                    printf("Turning on Light 2...\n");
                    light2Status = 1;
                }
                else
                {
                    printf("Turning off Light 2...\n");
                    light2Status = 0;
                }
                break;
            case 3:
                if(fanStatus == 0)
                {
                    printf("Turning on Fan...\n");
                    fanStatus = 1;
                }
                else
                {
                    printf("Turning off Fan...\n");
                    fanStatus = 0;
                }
                break;
            case 4:
                printf("Increasing temperature...\n");
                temp++;
                break;
            case 5:
                printf("Decreasing temperature...\n");
                temp--;
                break;
            case 6:
                printf("Increasing humidity...\n");
                humidity++;
                break;
            case 7:
                printf("Decreasing humidity...\n");
                humidity--;
                break;
            default:
                printf("Invalid choice!\n");
        }

        // display current status
        printf("Current Status:\n");
        printf("Light 1 is %s\n", light1Status == 1 ? "on" : "off");
        printf("Light 2 is %s\n", light2Status == 1 ? "on" : "off");
        printf("Fan is %s\n", fanStatus == 1 ? "on" : "off");
        printf("Temperature is %d Celsius\n", temp);
        printf("Humidity is %d%%\n", humidity);
    }

    return 0;
}