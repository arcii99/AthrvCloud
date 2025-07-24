//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include<stdio.h>

int search(int array[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(array[i] == key)
            return i;
    }
    return -1;
}

int main(void) {
    int array[] = {10, 30, 20, 50, 40, 80, 60, 70};
    int n = sizeof(array)/sizeof(array[0]); 
    int key = 50;
    int result = search(array, n, key);
    if(result == -1)
        printf("Key not found in the given array\n");
    else
        printf("Key found at index %d in the given array\n", result);
    return 0;
}