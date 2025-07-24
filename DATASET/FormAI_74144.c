//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to calculate total CPU time
void calTotalCPU(unsigned long long int *userTime, unsigned long long int *systemTime, unsigned long long int *idleTime)
{
    FILE *fp;
    char buffer[1024];
    unsigned long long int uTime,sTime,iTime;

    fp=fopen("/proc/stat","r");
    if(fp==NULL){
        printf("Cannot open file\n");
        exit(0);
    }

    fgets(buffer,sizeof(buffer),fp); // Get first line of the file
    sscanf(buffer,"%*s %llu %llu %llu",&uTime,&sTime,&iTime);
    *userTime=uTime;
    *systemTime=sTime;
    *idleTime=iTime;
    fclose(fp);
}

int main()
{
    unsigned long long int cpuTime1,cpuTime2,diffUser,diffSys,diffIdle,totalTime1,totalTime2,diffTotal;
    double cpuUsage;

    calTotalCPU(&cpuTime1,&cpuTime1,&totalTime1); // Get initial CPU usage

    printf("Program starting...\n");
    sleep(1); // Wait for 1 second

    calTotalCPU(&cpuTime2,&cpuTime2,&totalTime2); // Get second CPU usage

    diffUser=cpuTime2-cpuTime1;
    diffSys=cpuTime2-cpuTime1;
    diffIdle=totalTime2-totalTime1;
    diffTotal=diffIdle+diffSys+diffUser;

    cpuUsage=((double)(diffTotal-diffIdle)/(double)diffTotal)*100.0;

    printf("CPU Usage: %.2lf %%\n",cpuUsage);

    return 0;
}