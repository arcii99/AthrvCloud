//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
//Welcome to the Land of Strange and Unusual Searching Algorithms!

#include <stdio.h>

int StrangeSearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == x)
        {
            printf("Your element is found at index %d and it took a strange algorithm to find it!\n", mid1);
            return mid1;
        }

        if (arr[mid2] == x)
        {
            printf("Your element is found at index %d and it took a strange algorithm to find it!\n", mid2);
            return mid2;
        }

        if (x < arr[mid1])
        {
            printf("Say Hello to our friend Greedy!\n");
            return StrangeSearch(arr, low, mid1 - 1, x);
        }
        else if (x < arr[mid2])
        {
            printf("Say Hi to our friend Lazy!\n");
            return StrangeSearch(arr, mid1 + 1, mid2 - 1, x);
        }
        else
        {
            printf("Say Goodbye to our friends Greedy and Lazy, and welcome Mr. Clever!\n");
            return StrangeSearch(arr, mid2 + 1, high, x);
        }
    }
    printf("Unfortunately, your element is not found in the Land of Strange and Unusual Searching Algorithms...\n");
    return -1;
}

int main()
{
    int arr[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 21;

    int result = StrangeSearch(arr, 0, n - 1, x);
    printf("Your element's index: %d\n", result);

    return 0;
}