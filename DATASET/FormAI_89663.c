//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

int main() {
  int n=10;
  int arr[n];
  int i,j,k;
  for(i=0;i<n;i++) {
    arr[i]=rand()%50;
  }
  for(i=0;i<n;i++) {
    for(j=i+1;j<n;j++) {
      if(arr[i]>arr[j]) {
        k=arr[i];
        arr[i]=arr[j];
        arr[j]=k;
      }
    }
  }
  int sum=0;
  int subseq=0;
  for(i=0;i<n;i++) {
    sum+=arr[i];
    if(sum>50) {
      subseq++;
      sum=arr[i];
    }
    if(sum==50) {
      subseq++;
      sum=0;
    }
  }
  printf("The minimum number of subsequences is %d\n",subseq);
  return 0;
}