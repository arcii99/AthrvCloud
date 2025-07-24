//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

// Function to sort the elements in typical Increasing order
int compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

// Function for applying Greedy Algorithm
void greedy(int arr[], int n){
    int count = 1; // Initializing number of objects taken initially
    int weight = arr[0]; // Setting the initial weight value as first element
  
    for (int i = 1; i < n; i++) { // Checking rest of the elements in the array
        if (weight + arr[i] <= n) { // If current frame weight of objects taken is less than the maximum possible weight
            weight += arr[i]; // Adding the current element weight to the total weight
            count ++; // Increasing the count of objects taken
        }
    }
    printf("Maximum number of objects that can be packed is %d\n",count);
}

// Main Function
int main()
{
    int n, i;
    printf("Enter the number of objects you want to enter : ");
    scanf("%d",&n); // Reading the number of objects
  
    int arr[n]; // Initializing the array of objects
    printf("\nEnter the weights of each object : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]); // Reading the weight of each object and storing into array
    }
  
    qsort(arr, n, sizeof(int), compare); // Sorting the array in increasing order
    
    greedy(arr, n); // Applying Greedy Algorithm on sorted array to get the maximum number of objects that can be packed
    return 0;
}