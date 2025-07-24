//FormAI DATASET v1.0 Category: Educational ; Style: irregular
#include<stdio.h>

int main()
{
    int arr[10] = {5,3,8,4,2,7,1,9,6,0};
    int i,j,temp;
    for(i=0;i<9;i++)
    {
        for(j=0;j<(9-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}