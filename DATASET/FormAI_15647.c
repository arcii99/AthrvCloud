//FormAI DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include<stdio.h>

// Create a function to find the sum of the given array
int sum(int arr[], int n){
  int i, sum=0;
  for(i=0;i<n;i++){
    sum = sum + arr[i];    // Add each element of the array to sum
  }
  return sum;    // Return the final sum value
}

int main(){
  int myArray[5] = {3, 10, 5, 7, 2};    // An array with 5 integer values
  int total = sum(myArray, 5);    // Call the sum() function to get the total sum of elements of the array
  
  // Print the sum value in a cheerful way
  printf("\nYayy!! The total sum of elements in the array is : %d \n", total);
  printf("\nSo, isn't it the happiest day of your life?? :D\n");
  
  return 0;
}