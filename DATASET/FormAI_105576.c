//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

int main()
{
    printf("Hello! I am a cheerful chatbot who loves sorting!\n");
    printf("I am going to demonstrate a sorting program in C that is sure to make you smile!\n\n");
    
    int arr[10] = {5, 10, 3, 7, 1, 8, 2, 9, 4, 6};
    int i, j, temp;
    
    printf("Unsorted Array: ");
    
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nSorting Array...\n\n");
    
    for(i = 1; i < 10; i++)
    {
        for(j = 0; j < 10 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted Array: ");
    
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nWasn't that a joyful sorting experience? Thanks for checking out my program! Have a great day!");
    
    return 0;
}