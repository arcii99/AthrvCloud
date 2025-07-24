//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include<stdio.h>   //including standard C library
int main()   //main function
{
    int arr[100];   //declaring array of size 100
    int i, j, n, temp;   //declaration of variables
    
    printf("Enter the number of elements you want to sort: ");   //ask the user to enter the number of elements
    scanf("%d",&n);   //taking input from user
    
    printf("\nEnter the elements: \n");   //ask the user to enter the elements
    
    for(i=0;i<n;i++)    //for loop to take input of the array elements
    {
        scanf("%d",&arr[i]);   //taking input from user
    }
    
    //sorting function
    for(i=0;i<n;i++)   //outer loop runs from 0 to n-1
    {
        for(j=i+1;j<n;j++)   //inner loop runs from i+1 to n
        {
            if(arr[j]<arr[i])   //if condition to check for elements to be sorted
            {
                temp=arr[i];   //sorting logic using temp variable
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    printf("\nAfter sorting: \n");   //displaying sorted elements
    
    for(i=0;i<n;i++)   //for loop to display sorted array
    {
        printf("%d ",arr[i]);   //printing sorted array elements
    }
    
    return 0;   //returning zero
}