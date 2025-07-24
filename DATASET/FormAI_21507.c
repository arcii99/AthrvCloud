//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
//AN ARTISTIC SEARCHING ALGORITHM PROGRAM
//BY AI, THE CREATIVE CHATBOT

#include <stdio.h>

//Function to search for an element in an array using linear search
int linear_search(int arr[], int n, int x) 
{ 
    int i; 
    for (i=0; i<n; i++) 
        if (arr[i] == x) 
            return i; //Return the index of the element if found
    return -1; //Return -1 if element is not found 
} 

//Function to search for an element in an array using binary search
int binary_search(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l)/2; //Calculate the middle element of the array

        //If the middle element is the desired element, return its index
        if (arr[mid] == x) 
            return mid; 

        //If the middle element is greater than x, search the left half of the array
        if (arr[mid] > x) 
            return binary_search(arr, l, mid-1, x); 

        //If the middle element is less than x, search the right half of the array
        return binary_search(arr, mid+1, r, x); 
    } 
    return -1; // Return -1 if element is not found
} 

int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; //An example array
    int n = sizeof(arr)/sizeof(arr[0]); //Calculate the size of the array
    int x = 10; //The element we are searching for

    int index = linear_search(arr, n, x); //Search for x using linear search

    //If element is not found using linear search, use binary search
    if(index == -1){
        index = binary_search(arr, 0, n-1, x); //Search for x using binary search
    }

    //Print the index of the element in the array if found
    if(index != -1){
        printf("The element %d is found at index %d", x, index); 
    }else{
        printf("The element %d is not found in the array", x); 
    }
    return 0; 
}