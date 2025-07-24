//FormAI DATASET v1.0 Category: Random ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    srand(time(NULL)); //seed the random number generator with the current time
    
    //create an array of 10 random integers between 1 and 100
    int random_nums[10];
    for(i=0; i<10; i++)
    {
        random_nums[i] = rand() % 100 + 1;
        printf("Random Number %d: %d\n", i+1, random_nums[i]);
    }
    
    //find the largest and smallest number in the array
    int largest = random_nums[0];
    int smallest = random_nums[0];
    for(i=1; i<10; i++)
    {
        if(random_nums[i] > largest)
            largest = random_nums[i];
        if(random_nums[i] < smallest)
            smallest = random_nums[i];
    }
    printf("Largest Number: %d\n", largest);
    printf("Smallest Number: %d\n", smallest);
    
    //create a new array with the numbers sorted in ascending order
    int sorted_nums[10];
    int j, temp;
    for(i=0; i<10; i++)
    {
        sorted_nums[i] = random_nums[i];
        for(j=i+1; j<10; j++)
        {
            if(sorted_nums[j] < sorted_nums[i])
            {
                temp = sorted_nums[i];
                sorted_nums[i] = sorted_nums[j];
                sorted_nums[j] = temp;
            }
        }
    }
    
    //display the sorted array
    printf("Sorted Numbers:\n");
    for(i=0; i<10; i++)
    {
        printf("%d ", sorted_nums[i]);
    }
    
    return 0;
}