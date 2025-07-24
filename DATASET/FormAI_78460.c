//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function declarations
void printArray(int arr[], int size);
void selectionSort(int arr[], int size);

int main()
{
    printf("Welcome to the Magical Sorting program!\n\n");
    printf("In this program, we will demonstrate the magical power of selection sorting.\n");
    printf("We will use a magical array of randomly generated numbers to demonstrate how selection sorting works.\n\n");

    //Generate the magical array of numbers
    srand(time(0)); //Seed the random number generator
    int size = 10; //Size of the array
    int arr[size];
    printf("The magical array of numbers is: \n");
    for(int i=0; i<size; i++)
    {
        arr[i] = rand()%100; //Generate a random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    //Call the selection sort function to sort the array
    selectionSort(arr, size);

    printf("The magical array of numbers has been sorted using selection sorting.\n");
    printf("The sorted array is: \n");
    printArray(arr, size);

    return 0;
}

//Function to print the array
void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

//Function to perform selection sorting on the array
void selectionSort(int arr[], int size)
{
    printf("The magical powers of selection sorting are now at work...\n\n");
    int min, temp;
    for(int i=0; i<size-1; i++)
    {
        min = i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        printf("The magical sorting wand has waved, and the array has been transformed:\n");
        printArray(arr, size);
    }
    printf("The magical powers of selection sorting have been fully utilized.\n\n");
}