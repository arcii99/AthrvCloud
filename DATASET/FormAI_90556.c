//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
// Hey there! Welcome to my fancy sorting program! 

#include<stdio.h>

int main()
{
    int arr[10] = {20, 5, 70, 10, 25, 30, 45, 50, 15, 65}; // Here's my happy array
    int i, j, temp;
    
    printf("I have an amazing array that needs sorting! Let's get started!\n");

    // Time to sort this baby! 
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(arr[j]<arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The array now looks super neat and sorted in ascending order! Check it out:\n");

    // Loops through array for display
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nThis was awesome! Can't wait for our next sorting adventure! Thanks for playing along!\n");

    return 0;
}