//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,i,sum=0,*ptr;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  ptr=(int*)malloc(n*sizeof(int)); //Memory allocation using malloc function
  if(ptr==NULL){ //Checking if memory is allocated or not
      printf("Memory not allocated.\n");
      exit(0);
  }
  printf("Enter elements of array: ");
  for(i=0;i<n;i++){
      scanf("%d",ptr+i); //Storing values at the pointer address
      sum+=*(ptr+i); //Finding the sum of all array elements
  }
  printf("Sum of array elements= %d\n",sum); //Printing the sum of array elements
  free(ptr); //Freeing the memory
  return 0;
}