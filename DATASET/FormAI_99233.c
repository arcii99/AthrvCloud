//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include<stdio.h>
#include<stdlib.h>

//A unique searching algorithm that finds the index of a value in an array in a funny way.
int funny_search(int arr[], int n, int value){
   int i;
   //first, let's generate some random numbers
   srand(time(NULL));
   int r = rand() % 100;

   //now let's search for the index of the value in the array
   for(i = 0; i < n; i++){
      //if the current element is equal to the value, we got it!
      if(arr[i] == value){
         printf("Found %d at index %d in a hilarious way! ;)\n", value, i+r);
         return i+r;
      }
   }

   //if the value is not in the array, we still have some fun
   printf("Oopsie! Couldn't find %d in the array, but let's still chill and have a drink!\n", value);
   return -1;
}

//let's test the function with a small array
int main(){
   int arr[] = {2,5,1,7,3,4,9,8,10,6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int value = 8;
   int index = funny_search(arr, n, value);
   return 0;
}