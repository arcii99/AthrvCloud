//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include<stdio.h>

int main(){
   int n,i;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   int bt[n],p[n],wt[n],ta[n],ct[n],tat=0,wtTotal=0;
   float avwt,avta;
   for(i=0;i<n;i++){
      printf("Enter burst time for process %d: ",i+1);
      scanf("%d",&bt[i]);
      p[i]=i+1;          
   }
   ct[0]=bt[0];
   for(i=1;i<n;i++){
      ct[i]=ct[i-1]+bt[i];    
   }
   printf("\nPID \tBT \tCT \tTAT \tWT");
   for(i=0;i<n;i++){
      ta[i]=ct[i];
      wt[i]=ta[i]-bt[i];
      printf("\nP%d \t%d \t%d \t%d \t%d",p[i],bt[i],ct[i],ta[i],wt[i]);
      tat+=ta[i];
      wtTotal+=wt[i];    
   }
   avwt=(float)wtTotal/n;
   avta=(float)tat/n;
   printf("\n\nAverage Waiting Time = %.2f",avwt);
   printf("\nAverage Turnaround Time = %.2f",avta);
   return 0;
}