//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n)
{
    // Create an array of 10 buckets
    int buckets[10][n];
    
    // Create an array to keep track of how many elements are in each bucket
    int bucket_sizes[10] = {0};
    
    // Determine the maximum element in the array
    int max_element = array[0];
    for(int i = 1; i < n; i++)
    {
        if(array[i] > max_element)
            max_element = array[i];
    }

    // Divide each element in the array by the maximum element to get a percentage, 
    // then multiply by 10 to get the bucket number. 
    for(int i = 0; i < n; i++)
    {
        int bucket_num = (array[i] * 10) / (max_element + 1);
        buckets[bucket_num][bucket_sizes[bucket_num]] = array[i];
        bucket_sizes[bucket_num]++;
    }

    // Sort each bucket individually and copy the elements back into the original array
    int index = 0;
    for(int i = 0; i < 10; i++)
    {
        // Use bubble sort to sort elements in each bucket
        for(int j = 0; j < bucket_sizes[i]; j++)
        {
            for(int k = j + 1; k < bucket_sizes[i]; k++)
            {
                if(buckets[i][j] > buckets[i][k])
                {
                    // Swap the elements
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
        
        // Copy the elements back into the original array
        for(int j = 0; j < bucket_sizes[i]; j++)
        {
            array[index] = buckets[i][j];
            index++;
        }
    }
}

// Example usage
int main()
{
    int array[] = {33, 12, 5, 6, 7, 89, 21, 45, 67, 78};
    int n = sizeof(array) / sizeof(array[0]);
    
    printf("Original array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    bucket_sort(array, n);
    
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}