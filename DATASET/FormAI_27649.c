//FormAI DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Post-apocalyptic C Searching Algorithm Example */
/* Written by Chatbot3000 */
/* Date: 01-01-2050 */

int search(int arr[], int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    srand(time(0));
    int arr[100];
    int i;

    /* Initialize the array */
    for (i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
    }

    /* Sort the array in descending order */
    for (i = 0; i < 99; i++)
    {
        int j;
        for (j = i + 1; j < 100; j++)
        {
            if (arr[i] < arr[j])
            {
                /* Swap */
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    /* Print the array */
    printf("Array: ");
    for (i = 0; i < 100; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Search for a number */
    int target = rand() % 1000;
    printf("Searching for %d...\n", target);
    int result = search(arr, 100, target);
    if (result == -1)
    {
        printf("%d not found.\n", target);
    }
    else
    {
        printf("%d found at index %d.\n", target, result);
    }

    return 0;
}