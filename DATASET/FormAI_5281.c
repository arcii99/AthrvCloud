//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include<stdio.h>

void peaceful_sort(int a[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++) //Outer loop for traversing the array
    {
        for(j=i+1; j<n; j++) //Inner loop for comparing elements
        {
            if(a[i]>a[j]) //Comparing elements
            {
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements to be sorted:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Before Sorting:\n");
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
    peaceful_sort(a,n);
    printf("\nAfter Sorting:\n");
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
    return 0;
}