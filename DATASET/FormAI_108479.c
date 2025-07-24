//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
   int i,j,n,count,max_count=0,mode=0;
   float sum=0,mean,variance,std_deviation;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   float a[n],freq[n];
   
   printf("Enter %d elements\n",n);
   for(i=0;i<n;i++) {
      scanf("%f",&a[i]);
      sum+=a[i];
   }
   
   // Calculate Mean
   mean=sum/n;
   printf("\nMean = %.2f\n",mean);

   //Calculate Variance and Standard Deviation
   for(i=0;i<n;i++) {
      variance+=pow(a[i]-mean,2);
   }
   variance=variance/n;
   std_deviation=sqrt(variance);
   printf("\nVariance = %.2f\n",variance);
   printf("\nStandard Deviation = %.2f\n",std_deviation);

   // Calculate the Mode
   for(i=0;i<n;i++) {
      count=0;
      for(j=0;j<n;j++) {
         if(a[j]==a[i])
         count++;
      }
      freq[i]=count;
   }
   for(i=0;i<n;i++) {
      if(freq[i]>max_count) {
         max_count=freq[i];
         mode=i;
      }
   }
   printf("\nMode = %.2f\n",a[mode]);

   return 0;
}