//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, temp;
    int arr[10];

    // initialize random seed
    srand(time(NULL));

    // generate random numbers for array
    printf("The numbers are: ");
    for(i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    
    // prepare for sorting by equipping a knight
    printf("\nA knight arrives with a lance and a shield.\n");
    printf("The lance represents the current element being sorted.\n");
    printf("The shield represents a temporary holder for elements being swapped.\n");

    // sorting with the help of the knight
    for(i = 0; i < 10; i++)
    {
        printf("\n\nThe knight prepares to sort the %dth element.\n", i+1);

        // start sorting with the lance
        for(j = i+1; j < 10; j++)
        {
            printf("\nThe knight advances with his lance toward the %dth element.\n", j+1);

            // if knight's lance is greater than element being checked, swap places with shield
            if(arr[i] > arr[j])
            {
                printf("\nThe knight pierces his lance through the %dth element.\n", j+1);

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                printf("The knight swaps his shield with the %dth element.\n", j+1);
                printf("The element with the lance is now %d, and the shield contains %d.\n", arr[i], arr[j]);
            }
            else
            {
                printf("\nThe knight withdraws his lance, and proceeds to the next element.\n");
            }
        }
    }

    // print sorted array
    printf("\n\nThe knight has finished sorting the array.\n");
    printf("The sorted numbers are: ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    // farewell to the knight
    printf("\n\nThe knight departs, leaving behind a sorted array.");
    printf("\nAll hail the sorting knight!");

    return 0;
}