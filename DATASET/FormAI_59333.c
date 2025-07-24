//FormAI DATASET v1.0 Category: Sorting ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10  //size of the array to be sorted

void print_array(int arr[]); //function to print the array
void bubble_sort(int arr[]); //function to sort the array using bubble sort

int main()
{
    int arr[ARRAY_SIZE]; //array to be sorted
    srand(time(NULL)); //initialize random seed

    //fill the array with random numbers between 1 and 100
    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % 100 + 1;
    }

    printf("Welcome to Retro Sort!\n\n");
    printf("Here is your unsorted array:\n");
    print_array(arr);

    printf("\n\nSorting your array with Bubble Sort...\n");
    bubble_sort(arr);

    printf("\n\nHere is your sorted array:\n");
    print_array(arr);

    printf("\n\nThat's how we used to sort back in the old days!\n\n");

    return 0;
}

//function to print the array
void print_array(int arr[])
{
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
}

//function to sort the array using bubble sort
void bubble_sort(int arr[])
{
    for(int i = 0; i < ARRAY_SIZE-1; i++){
        for(int j = 0; j < ARRAY_SIZE-1-i; j++){
            if(arr[j] > arr[j+1]){
                //swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}