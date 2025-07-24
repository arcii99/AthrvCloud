//FormAI DATASET v1.0 Category: Data mining ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function to generate random integers*/
int rand_gen(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

/*Function to calculate average of the given array*/
float average(int arr[], int n)
{
    float sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    return (sum/n);
}

/*Main function*/
int main()
{
    srand(time(0));       //Seed for random function
    int n=10;              //Size of the array
    int arr[n];            //Array to store random integers
    int lower=1, upper=100; //Range for random numbers
    
    /*Generating random integers and storing in array*/
    printf("Generated random array: ");
    for(int i=0; i<n; i++)
    {
        arr[i]=rand_gen(lower, upper);
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    /*Calculating average*/
    float avg=average(arr, n);
    printf("Average of the generated array is: %.2f\n", avg);
    
    /*Shape shifting the array*/
    printf("Shape-shifted array: ");
    int temp=arr[n-1];
    for(int i=n-1; i>=1; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}