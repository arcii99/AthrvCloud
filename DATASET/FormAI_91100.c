//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>
int main()
{
   int i,j,n;
   int bt[20], wt[20], tat[20], avwt=0, avtat=0; //bt = Burst Time, wt = Wait Time, tat = Turn Around Time
   printf("Enter total number of processes(maximum 20):");
   scanf("%d",&n);
   printf("\nEnter Process Burst Time\n");
   for(i=0;i<n;i++)
   {
       printf("P[%d]:",i+1);
       scanf("%d",&bt[i]);
   }
   wt[0]=0;    //waiting time for first process is 0
   //FCFS Algorithm
   for(i=1;i<n;i++)
   {
       wt[i]=0;
       for(j=0;j<i;j++)
           wt[i]+=bt[j];
   }
   printf("\nProcess\t\tBurst Time\t\tWait Time\t\tTurnaround Time");
   for(i=0;i<n;i++)
   {
       tat[i]=bt[i]+wt[i];
       avwt+=wt[i];
       avtat+=tat[i];
       printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
   }
   avwt/=i;
   avtat/=i;
   printf("\n\nAverage Waiting Time:%d",avwt);
   printf("\nAverage Turnaround Time:%d",avtat);
   return 0;
}