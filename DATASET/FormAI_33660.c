//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // initialize an array of integers
    int search_val = 70; // value to search for
    int found = 0; // set initial found value to false

    printf("Searching for value %d...\n", search_val);

    for(int i=0; i<10; i++) { // iterate through array
        if(arr[i] == search_val) { // if value is found
            printf("Value found at position %d\n", i); // print position of value
            found = 1; // set found value to true
            break; // exit loop
        }
    }

    if(!found) { // if value is not found
        printf("Value not found in array.\n"); // print message
    }

    return 0; // exit program
}