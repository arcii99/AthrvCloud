//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){

   FILE *fp;
   char buffer[60];
   float cpuUsage=0.0;
   int cpuTime[2][4]; // dual sets of CPUTIME
   int i=0;
   long int jiffies_1=0,jiffies_2=0;
  
   fp=fopen("/proc/stat","r");
   for(i=0;i<4;i++)
        fscanf(fp,"%s %d %d %d %d %d %d %d",buffer,&cpuTime[0][i],&cpuTime[1][i],&cpuTime[2][i],&cpuTime[3][i],&cpuTime[4][i],&cpuTime[5][i],&cpuTime[6][i]);
    fclose(fp);

   for(i=0;i<4;i++)
        jiffies_1+=cpuTime[0][i]+cpuTime[1][i]+cpuTime[2][i]+cpuTime[5][i]+cpuTime[6][i];

   usleep(1000000);

   fp=fopen("/proc/stat","r");
   for(i=0;i<4;i++)
        fscanf(fp,"%s %d %d %d %d %d %d %d",buffer,&cpuTime[0][i],&cpuTime[1][i],&cpuTime[2][i],&cpuTime[3][i],&cpuTime[4][i],&cpuTime[5][i],&cpuTime[6][i]);
   fclose(fp);

   for(i=0;i<4;i++)
        jiffies_2+=cpuTime[0][i]+cpuTime[1][i]+cpuTime[2][i]+cpuTime[5][i]+cpuTime[6][i];

   cpuUsage=((float)(jiffies_2-jiffies_1)/10000000)*100;

   printf("CPU usage: %.2f%c\n",cpuUsage,'%');

   return 0;

}