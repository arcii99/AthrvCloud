//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include<stdio.h>

int main() {
   int arr[10] = {21, 12, 35, 43, 26, 80, 67, 99, 49, 75};
   int key, flag=0; // flag is for checking if the element is present in the array or not.
   printf("Enter the Element to be Searched: ");
   scanf("%d",&key);
   
   for(int i=0;i<10;i++){
        if(arr[i] == key){
            printf("\nThe Element %d is Found at Position %d",key,i+1);
            flag = 1;
            break; // break from the loop if element is found.
        }   
   }   

   if(flag == 0) 
        printf("\nThe Element %d is Not Present in the Given Array",key);
        
   return 0;
}