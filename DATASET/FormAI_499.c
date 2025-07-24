//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100000000; // number of elements in arrays
    int *arr1 = (int*) malloc(n*sizeof(int));
    int *arr2 = (int*) malloc(n*sizeof(int));
    int i; // counter variable

    // Initialize arrays with random values
    for(i=0;i<n;i++) {
        arr1[i] = rand(); 
        arr2[i] = rand();
    }

    // add values of arr2 into arr1
    for(i=0;i<n;i++) {
        arr1[i] += arr2[i];
    }

    // check if arrays were added correctly
    int correct = 1; // assume arrays were added correctly
    for(i=0;i<n;i++) {
        if(arr1[i] != arr2[i]+arr2[i]) { // check if arr1[i] == arr2[i]+arr2[i]
            correct = 0;
            break;
        }
    }

    // print result
    if(correct) {
        printf("Arrays were successfully added!\n");
    } else {
        printf("Error encountered while adding arrays.\n");
    }

    // free memory used by arrays
    free(arr1);
    free(arr2);

    return 0;
}