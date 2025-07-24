//FormAI DATASET v1.0 Category: Data mining ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Recursive function to find the maximum element in an array using divide-and-conquer strategy
int max(int arr[], int l, int r)
{
    if(l == r) //base case
        return arr[l];
    else
    {
        int m = (l+r)/2; //finding the middle index
        int a = max(arr, l, m); //maximum element in left half
        int b = max(arr, m+1, r); //maximum element in right half
        return a > b ? a : b; //return the maximum of two
    }
}

int main()
{
    int n, i, arr[MAX], max_element;

    printf("Enter the number of elements (1-100) : ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX) //validation check for n
    {
        printf("Invalid Input, try again!\n");
        exit(0);
    }

    printf("Enter the %d elements : ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max_element = max(arr, 0, n-1); //calling the recursive function

    printf("The maximum element in the given array is : %d", max_element);

    return 0;
}