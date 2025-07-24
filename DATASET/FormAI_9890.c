//FormAI DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a custom struct to hold happy numbers
typedef struct {
    int number;
    char* message;
} HappyNumber;

// Define function to compare two HappyNumbers
int compareHappyNumber(const void* a, const void* b) {
    HappyNumber* numA = (HappyNumber*)a;
    HappyNumber* numB = (HappyNumber*)b;

    if(numA->number < numB->number) {
        return -1;
    } else if(numA->number > numB->number) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create an array of HappyNumbers
    HappyNumber numbers[] = {
        {10, "Yay! Double digits!"},
        {7, "Lucky number 7!"},
        {144, "Fibonacci!"},
        {3, "Third time's the charm!"},
        {42, "The answer to life, the universe, and everything!"},
        {23, "Michael Jordan's number!"},
        {99, "Almost 100!"},
        {2022, "The year we'll all be living in!"},
        {17, "Prime time!"},
        {8, "Great number for a spider!"},
        {50, "Halfway to 100!"},
        {100, "A perfect score!"},
        {666, "Beastly!"},
        {9, "Almost perfect!"},
        {69, "Nice!"},
        {420, "Blaze it!"},
        {1, "The start of something great!"},
        {0, "Nothing can stop me!"}
    };

    int numNumbers = sizeof(numbers)/sizeof(HappyNumber);

    // Sort the array using qsort from the stdlib library
    qsort(numbers, numNumbers, sizeof(HappyNumber), compareHappyNumber);

    // Print out the array in its sorted order along with its happy message
    printf("Behold! The sorted happy numbers:\n\n");

    for(int i = 0; i < numNumbers; i++) {
        printf("%d - %s\n", numbers[i].number, numbers[i].message);
    }

    return 0;
}