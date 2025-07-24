//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, n, r;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));

    printf("The random numbers between 0 and 100 are: ");
    for(i=0;i<n;i++)
    {
        r = rand()%101;
        arr[i] = r;
        printf("%d ",r);
    }

    printf("\n\nThe sorted array is: ");
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        printf("%d ",arr[i]);
    }

    return 0;
}