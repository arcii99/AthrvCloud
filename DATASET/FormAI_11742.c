//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[100], num, found=0, i;

    // initialize array with random numbers
    srand(time(NULL));
    for(i=0; i<100; i++) {
        arr[i] = rand()%1000;
    }

    printf("Enter the number to search: ");
    scanf("%d", &num);

    // linear search algorithm
    for(i=0; i<100; i++) {
        if(num == arr[i]) {
            printf("Hooray! The number %d is found at index %d\n", num, i);
            found = 1; // set flag to indicate that number is found
            break; // exit loop if number is found
        }
    }

    if(!found) {
        printf("Oops! The number %d is not found in the array\n", num);
    }

    return 0;
}