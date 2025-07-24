//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};  // Integer array to hold 10 numbers
    int count = 0;  // Counter variable to keep track of number of even integers
    int i;  // Iterator variable
    float avg;  // Variable to hold average of even numbers
    
    /* Loop through the array to check for even numbers and calculate their average */
    for(i=0; i<10; i++)
    {
        if(array[i]%2 == 0)  // Check if number is even
        {
            count++;  // Increment count of even numbers
            avg += array[i];  // Add even number to average
        }
    }
    
    avg /= count;  // Calculate average by dividing total even numbers by count
    
    printf("The average of even numbers in the array is: %.2f\n",avg);  // Print average with 2 decimal places
    
    return 0;
}