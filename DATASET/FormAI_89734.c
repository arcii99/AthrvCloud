//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>

int main() {
   int n = 5; //number of jobs
   int s[n],f[n]; //starting time and ending time arrays
   int i, j, temp1, temp2; //loop variables and temporary variables 

   //input the starting time and ending time for each job
   printf("Enter the starting time and ending time for each job: \n");
   for(i=0;i<n;i++) {
      printf("Job %d: ",i+1);
      scanf("%d %d",&s[i],&f[i]);
   }

   //sort the jobs according to ending time (earliest deadline first)
   for(i=0;i<n-1;i++) {
      for(j=0;j<n-i-1;j++) {
         if(f[j]>f[j+1]) {
            //swap the ending time
            temp1 = f[j];
            f[j] = f[j+1];
            f[j+1] = temp1;
            //swap the starting time
            temp2 = s[j];
            s[j] = s[j+1];
            s[j+1] = temp2;
         }
      }
   }

   //initialize variables
   int count=1, last=f[0];
   printf("Selected jobs: Job 1 ");
   
   //select the jobs with the earliest deadlines (Greedy algorithm)
   for(i=1;i<n;i++) {
      if(s[i]>=last) {
         count++;
         printf("Job %d ",i+1);
         last = f[i];
      }
   }
   printf("\nTotal number of jobs selected: %d\n",count);
   
   return 0;
}