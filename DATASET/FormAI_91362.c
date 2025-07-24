//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: creative
//This program demonstrates the use of pointers in a performance-critical component
#include <stdio.h>

int main() {
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    int *ptr = arr;

    //iterate through array using pointer
    for (int i = 0; i < 1000; i++) {
        printf("%d ", *ptr);
        ptr++;
    }

    return 0;
}