//FormAI DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int temp_sensor;
    time_t t;
    
    srand((unsigned) time(&t)); //Initializing random number generator
    
    for(int i=0; i<50; i++)
    {
        temp_sensor = rand() % 100 + 1; //Generating random temperature value between 1 and 100
        
        if(temp_sensor > 80)
        {
            printf("Temperature is extremely high! Please turn on the AC.\n");
        }
        else if(temp_sensor > 60 && temp_sensor <= 80)
        {
            printf("Temperature is at a comfortable level.\n");
        }
        else if(temp_sensor > 40 && temp_sensor <= 60)
        {
            printf("Temperature is low! Please turn on the heater.\n");
        }
        else
        {
            printf("Temperature is dangerously low! Please take necessary precautions.\n");
        }
        
        printf("Temperature reading: %d\n", temp_sensor);
        printf("------------------------------\n");
        
        sleep(2); //Delay for 2 seconds before the next temperature reading
    }
    
    return 0;
}