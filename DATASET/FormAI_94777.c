//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
/* A unique traffic light controller program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void redLight();
void greenLight();
void yellowLight();

int main()
{
    int i;
    srand(time(NULL));
    
    printf("Traffic light controller started...\n\n");
    
    for(i = 1; i <= 10; i++)
    {
        int random = rand() % 3;
        
        if(random == 0)
        {
            redLight();
        }
        else if(random == 1)
        {
            greenLight();
        }
        else
        {
            yellowLight();
        }
        
        printf("Traffic light has been on for 5 seconds\n");
        printf("Next light will turn on in 3 seconds\n\n");
        
        // Wait for 3 seconds
        sleep(3);
    }
    
    printf("\nTraffic light controller stopped\n");
    return 0;
}

void redLight()
{
    printf("RED light is on\n");
    printf("All vehicles must stop\n");
}

void greenLight()
{
    printf("GREEN light is on\n");
    printf("All vehicles can go\n");
}

void yellowLight()
{
    printf("YELLOW light is on\n");
    printf("All vehicles should slow down and prepare to stop\n");
}