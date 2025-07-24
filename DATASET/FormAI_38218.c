//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include<stdio.h>

int search(int arr[], int n, int x){
  int i;
  for (i=0; i<n; i++){
    if (arr[i] == x){
        printf("Hurray! We found %d at position %d!!\n", x, i);
        return i;
    }
  }
  printf("Oops! We couldn't find %d in the array.\n", x);
  return -1;
}

int main(){
  int arr[] = {2, 4, 7, 10, 13, 18, 20};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x;
  printf("***WELCOME TO ENERGETIC SEARCH PROGRAM***\n");
  printf("Please enter the number you want to search: ");
  scanf("%d", &x);
  search(arr, n, x);
  return 0;
}