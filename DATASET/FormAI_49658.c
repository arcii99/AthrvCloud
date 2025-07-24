//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);

  int *arr = (int*)malloc(n*sizeof(int));
  int sum = 0;

  for(int i=0;i<n;i++){
    printf("Enter element %d: ",i+1);
    scanf("%d",&arr[i]);
  }

  //Sorting the array in ascending order
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  int i = 0;
  while(arr[i]<0){
    sum+=arr[i];
    i++;
  }

  printf("Maximum sum of negative numbers: %d",sum);

  free(arr);
  return 0;
}