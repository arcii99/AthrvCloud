//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int i,j;
    double speed;
    
    char *buffer = (char*)malloc(1000*sizeof(char));
    if(buffer==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    
    //start clock
    start = clock();
    //running internet speed test 
    printf("Running internet speed test......\n");
    
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
        {
            buffer[j] = 'a'+(rand()%26);
        }
        printf("Data sent: %s\n", buffer);
    }
    //stop clock
    end = clock();
    //calculate time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    //calculate the internet speed
    speed = (1000000*8)/(cpu_time_used*pow(10,6));
    
    printf("The internet speed is: %f Mbps\n", speed);
    free(buffer);
    
    return 0;
}