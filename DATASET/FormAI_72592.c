//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include<stdio.h>

int main(){
  int input[10],i;
  float output[10],sum,average;
  
  printf("Enter 10 integer values:\n");
  
  for(i=0;i<10;i++){
    scanf("%d",&input[i]);
  }
  
  for(i=0;i<10;i++){
    sum+=input[i];
  }
  
  average=sum/10;
  
  for(i=0;i<10;i++){
    output[i]=input[i]-average;
  }
  
  printf("The original array is:\n");
  
  for(i=0;i<10;i++){
    printf("%d\t",input[i]);
  }
  
  printf("\nThe output array after processing is:\n");
  
  for(i=0;i<10;i++){
    printf("%f\t",output[i]);
  }
  
  return 0;
}