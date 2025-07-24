//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include<stdio.h>
int main()
{
    int n, i, key, search_result = -1;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched:\n");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            search_result = i;
            break;
        }
    }
    if(search_result == -1)
    {
        printf("%d not found in the array.\n", key);
    }
    else
    {
        printf("%d found at index %d.\n",key,search_result);
    }
    return 0;
}