//FormAI DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
// Romeo and Juliet's Sorting Program

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("\nRomeo: My heart just swapped like these integers\n");
    printf("Juliet: Oh Romeo, you always have a witty remark\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("\nRomeo: Our love story is like bubble sort\n");
    printf("Juliet: How so, Romeo?\n");
    printf("Romeo: With each iteration, our love grows stronger and purer\n");
}

int main()
{
    int arr[] = {9, 3, 7, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nRomeo: Juliet, I have an unsorted list of integers. Will you help me sort them?\n");
    printf("Juliet: Of course, Romeo. We can use bubble sort algorithm\n");
    bubble_sort(arr, n);
    printf("\nRomeo: Our integers are now sorted! Let us celebrate our love and this magnificent algorithm\n");
    printf("Juliet: Oh Romeo, you always find romance in the mundane tasks\n");
    return 0;
}