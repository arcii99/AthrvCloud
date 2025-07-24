//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num[10], temp;
    srand(time(NULL)); // seed the random function with current time
    for(int i = 0; i < 10; i++) {
        num[i] = rand() % 100; // generate random numbers between 0 and 99
    }
    printf("Before sorting:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    // bubble sort
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9 - i; j++) {
            if(num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    printf("After sorting:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}