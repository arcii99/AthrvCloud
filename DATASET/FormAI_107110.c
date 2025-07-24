//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

int main() {
  int num;
  printf("How many numbers do you want to enter? ");
  scanf("%d",&num);
  int* arr = (int*)malloc(num*sizeof(int));   // Dynamic memory allocation
  printf("Enter the %d numbers: ",num);
  for(int i = 0; i < num; i++) {
      scanf("%d",&arr[i]);
  }
  printf("Your entered numbers: ");
  for(int i = 0; i < num; i++) {
      printf("%d ",arr[i]);
  }
  printf("\n");

  int temp;  // to hold the temporary value of swapping
  for(int i = 0; i < num-1; i++) {
      for(int j = 0; j < num-i-1; j++) {
          if(arr[j] > arr[j+1]) {
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
          }
      }
  }

  printf("Sorted numbers: ");
  for(int i = 0; i < num; i++) {
      printf("%d ",arr[i]);
  }
  printf("\n");

  free(arr);  // Deallocating the memory block

  return 0;
}