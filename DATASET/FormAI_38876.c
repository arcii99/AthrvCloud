//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
//Welcome to my Unique C Searching Algorithm program!
//This program is designed to search for a specific number within an array of integers.

#include <stdio.h>

int search(int arr[], int size, int num) //This function takes three parameters, arr - the array, size - the size of the array, and num - the number to be searched
{
    int i; //Variable used for iteration

    for(i=0;i<size;i++) //Loop through the entire array
    {
        if(arr[i] == num) //If the number at the current index matches the number to be searched
        {
            return i; //Return the index where the number was found
        }
    }

    return -1; //If the number was not found, return -1
}

int main()
{
    int arr[] = {1, 5, 3, 8, 4, 9, 2, 7, 6}; //This is our test array
    int size = sizeof(arr)/sizeof(arr[0]); //Calculate the size of the array using sizeof operator
    int num = 4; //This is the number we are searching for in the array

    int result = search(arr, size, num); //Call the search function

    if(result == -1) //If search function returns -1, then the number was not found
    {
        printf("Sorry! The number %d was not found in the array.", num); //Print error message
    }
    else //Else print the index where the number was found
    {
        printf("The number %d was found at index %d in the array.", num, result); 
    }

    return 0;
}