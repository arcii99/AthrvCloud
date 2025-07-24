//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hey there, let's play a game of greedy algorithm!\n");
  int n;
  printf("How many integers would you like to sort?\n");
  scanf("%d", &n);
  int arr[n];
  printf("Please input your integers:\n");

  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  printf("Your input array: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }

  printf("\n");

  int temp,min;
  for(int i=0;i<n;i++){
    min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
        min=j;
      }
    }
    if(min!=i){
      temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
    }
  }

  printf("Sorted array using selection sort: ");
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
  printf("Woo hoo, looks like your array is now sorted using greedy algorithm!\n");

  return 0;
}