//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function prototype for generating random numbers
int generateRandomNumber(int min, int max);

//Function prototype for sorting an array
void bubbleSort(int arr[], int n);

int main()
{
    //Declare and initialize array
    int arr[10] = {0};

    //Generate random numbers and fill the array
    srand(time(0));
    for(int i=0; i<10; i++)
        arr[i] = generateRandomNumber(1,100);

    //Print unsorted array
    printf("Unsorted array:\n");
    for(int i=0; i<10; i++)
        printf("%d\t", arr[i]);

    //Sort the array using bubble sort
    bubbleSort(arr, 10);

    //Print sorted array
    printf("\n\nSorted array:\n");
    for(int i=0; i<10; i++)
        printf("%d\t", arr[i]);

    return 0;
}

//Function to generate random numbers within a given range
int generateRandomNumber(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//Function to perform bubble sort on an array
void bubbleSort(int arr[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}