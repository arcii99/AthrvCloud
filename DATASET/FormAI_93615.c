//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>

int main() 
{
    int n, i, j, temp, count=0, max_count=1, flag=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Original Array: ");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    //Greedy Algo starts
    for(i=1; i<n; i++) {
        if(arr[i-1] >= arr[i] && flag==0) {
            flag=1;
            count+=2;
        }
        else if(arr[i-1] >= arr[i] && flag==1) {
            count++;
        }
        else if(arr[i-1] < arr[i]) {
            if(count > max_count)
                max_count = count;
            count = 0;
            flag = 0;
        }
    }
    if(count > max_count)
        max_count = count;

    printf("\nMaximum number of decreasing subarrays: %d",max_count);
    return 0;
}