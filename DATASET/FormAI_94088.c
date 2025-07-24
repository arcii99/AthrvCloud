//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
//Let's create a unique searching algorithm that guarantees to find your desired element!
#include<stdio.h>

//We first create a function that searches for an element and returns its index if found, otherwise returns -1.
int findElement(int arr[], int n, int x){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == x)
            return i;
    }
    return -1; //element not found
}

int main(){
    int arr[50], n, x, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    //Let's fill our array with some random elements for testing
    for(i = 0; i < n; i++){
        arr[i] = rand();
    }
    
    printf("Enter the element that you want to search: ");
    scanf("%d", &x);
    
    //We call our searching function
    int index = findElement(arr, n, x);
    
    //If our function finds the element, we print its index. If not, we print a message indicating that the element was not found
    if(index != -1)
        printf("The element %d is at index %d in the array.\n", x, index);
    else
        printf("The element %d was not found in the array.\n", x);
        
    return 0;
}