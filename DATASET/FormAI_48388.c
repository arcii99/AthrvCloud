//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //Initializing an array of integers
    int nums[10] = {69, 420, 1337, 78, 666, 42069, 69, 69, 777, 420};

    //Printing original array
    printf("Original Array: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    //Sorting the array using bubble sort
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10-i-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                //Swapping adjacent elements if they are in wrong order
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    //Printing sorted array
    printf("Sorted Array: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    //Adding some humor to make it more interesting
    printf("\n");
    printf("Welcome to the Sorting Simulator!\n");
    printf("Today we will be sorting an array of integers in the most entertaining way possible.\n");
    printf("Our array consists of the following numbers: 69, 420, 1337, 78, 666, 42069, 69, 69, 777, 420.\n");
    printf("Who says sorting has to be boring?\n");
    printf("\n");
    printf("Now let's run the simulation and watch as the numbers fall into place...\n");
    printf("\n");
    sleep(1);

    //Simulating the sorting process
    printf("Sorting...\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10-i-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                sleep(1);
                for(int k = 0; k < 10; k++)
                {
                    if(k == j || k == j+1)
                    {
                        printf("\033[1;31m");
                    }
                    else
                    {
                        printf("\033[0m");
                    }
                    printf("%d ", nums[k]);
                }
                printf("\n");
            }
        }
    }

    //Final message after sorting
    printf("\n");
    printf("And there you have it! Our array is now sorted in ascending order.\n");
    printf("Thanks for tuning in to the Sorting Simulator and we hope to see you again soon!\n");

    return 0;
}