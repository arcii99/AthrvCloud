//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed with time
    
    int redTime = rand() % 16 + 30; //randomly selecting red light duration between 30-45 seconds
    int yellowTime = 3; //fixed duration of 3 seconds for yellow light
    int greenTime = rand() % 16 + 30; //randomly selecting green light duration between 30-45 seconds
    
    while(1) //infinite loop for continuous operation
    {
        //red light ON
        printf("RED\n");
        for(int i=0; i<redTime; i++)
        {
            printf("%d\n", redTime-i); //display remaining time
            sleep(1); //wait for 1 second
        }
        printf("YELLOW\n"); //yellow light ON after red light
        for(int i=0; i<yellowTime; i++)
        {
            printf("%d\n", yellowTime-i); //display remaining time
            sleep(1); //wait for 1 second
        }
        printf("GREEN\n"); //green light ON after yellow light
        for(int i=0; i<greenTime; i++)
        {
            printf("%d\n", greenTime-i); //display remaining time
            sleep(1); //wait for 1 second
        }
    }
    return 0;
}