//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include<stdio.h>
#include<math.h>

int main()
{
  int n,i,j,x;
  float sum,avg,deviation,standard_deviation;
  printf("Enter the number of integers to be entered: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter the integers: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  avg=sum/n; //Calculating Mean
  printf("The Mean of the entered integers is: %.2f\n",avg);

  for(i=0;i<n;i++)
  {
    deviation+=pow((a[i]-avg),2); //Calculating Deviation
  }
  deviation=sqrt(deviation/n); //Calculating Standard Deviation
  printf("The Standard Deviation of the entered integers is: %.2f\n",deviation);

  printf("The integers below the mean are: ");
  for(j=0;j<n;j++)
  {
    if(a[j]<avg)
    {
      printf("%d ",a[j]); //Printing Integers below Mean
    }
  }

  printf("\nThere are %d integers above and %d integers below the mean",x,n-x); //Printing amount of integers above and below the mean

  return 0;
}