//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include<stdio.h>

int main()
{
    int time = 0;
    char light = 'R';
    int count = 0;
    
    while(count < 10) // The system will work for 10 cycles
    {
        if(light == 'R')
        {
            printf("Red Light ON for 5 seconds\n");
            for(time=0; time<5; time++)
            {
                printf("%d seconds passed.\n",time+1);
            }
            light = 'G';
        }
        
        else if(light == 'G')
        {
            printf("Green Light ON for 10 seconds\n");
            for(time=0; time<10; time++)
            {
                printf("%d seconds passed.\n",time+1);
            }
            light = 'O';
        }
        
        else
        {
            printf("Orange Light ON for 3 seconds\n");
            for(time=0; time<3; time++)
            {
                printf("%d seconds passed.\n",time+1);
            }
            light = 'R';
            count++;
        }
    }
    
    printf("\nThe Traffic Light Control System Run for %d cycles.\n",count);
    printf("Terminating the Program.\n");
    
    return 0;
}