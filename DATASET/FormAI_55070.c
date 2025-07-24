//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#define MAX_INPUT_SIZE 100 //Defining macro to set maximum input size

int main()
{
    int i, j, k, size, sum;
    int *array;

    printf("Enter the size of the array : ");
    scanf("%d", &size);

    if(size > MAX_INPUT_SIZE) //Checking if size is less than the maximum input size
    {
        printf("Error! Maximum input size exceeded.");
        return 0; //Returning if maximum input size is exceeded
    }

    array = (int*)malloc(size * sizeof(int)); //Dynamic memory allocation of array

    printf("Enter the elements of the array : ");

    for(i=0; i<size; i++)
    {
        scanf("%d", (array + i)); //Taking input array elements from user
    }

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            sum = *(array + i) + *(array + j); //Storing sum of two elements in array
            for(k=j+1; k<size; k++)
            {
                if(sum == *(array + k)) //Checking if sum is equal to other elements in array
                {
                    printf("The triplet with sum equal to %d is : (%d, %d, %d)\n", sum, *(array + i), *(array + j), *(array + k));
                }
            }
        }
    }

    free(array); //Freeing dynamically allocated memory

    return 0;
}