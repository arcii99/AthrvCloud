//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a random number
int randomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Function to check if the number already exists
int check(int arr[], int num, int size) {
    for(int i=0; i<size; i++) {
        if(arr[i] == num) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to play Bingo
int bingo(int arr[], int size, int count) {
    int num = randomNumber(1, 75);
    // Check if the number exists in the array
    if(check(arr, num, size)) {
        arr[size] = num;
        printf("Number called: %d\n", num);
        size++;
        count++;
        // Check if all the numbers have been called
        if(size == 75) {
            printf("BINGO! All the numbers have been called.\n");
            return count;
        } else {
            return bingo(arr, size, count);
        }
    } else {
        return bingo(arr, size, count);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    printf("*** Welcome to the Bingo Simulator ***\n");
    int arr[75] = {0};
    int size = 0;
    int count = 0;
    count = bingo(arr, size, count);
    printf("Total number of calls: %d\n", count);
    return 0;
}