//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[50], n, i, j, temp;

int main()
{
    printf("Hi! Welcome to my sorting program!\n");
    printf("Please enter the number of elements you want to sort: ");
    scanf("%d", &n);
    printf("Great! Now, please enter the elements you want to sort:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\n");

    printf("Awesome! Let's sort the elements now!\n");

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\n");

    printf("Excellent! The elements have been sorted in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
    printf("Thank you for using my sorting program! I hope it was helpful!\n");

    return 0;
}