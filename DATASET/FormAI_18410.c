//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include<stdio.h>

int main()
{
  int num;
  int input_arr[100];
  int i,j,temp; 
  
  printf("Enter the number of elements in the array: ");
  scanf("%d",&num);

  printf("Enter %d integers\n", num);
 
  for(i=0;i<num;i++)
      scanf("%d",&input_arr[i]);
 
  for(i=0;i<num;i++)
  {
    for(j=i+1;j<num;j++)
    {
      if(input_arr[i]>input_arr[j])
      {
        temp=input_arr[i];
        input_arr[i]=input_arr[j];
        input_arr[j]=temp;
      }
    }
  }

  printf("\nSorted elements are: ");
  for(i=0;i<num;i++)
      printf(" %d",input_arr[i]);

  return 0;
}