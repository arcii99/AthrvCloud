//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int main() {
    printf("What?! You want me to write a searching algorithm program in C from scratch?! *Gasp* ");
    int values[] = { 10, 20, 30, 40, 50, 60 };
    int n = sizeof(values)/sizeof(int);
    int target = 30;
    int first = 0;
    int last = n - 1;
    int middle = (first + last)/2;
    while (first <= last) {
        if (values[middle] < target)
            first = middle + 1;
        else if (values[middle] == target) {
            printf("OMG, I found it! The target value %d is at index %d.\n", target, middle);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last)/2;
    }
    if (first > last)
        printf("NOOOO! The target value %d could not be found in the array!\n", target);
    return 0;
}