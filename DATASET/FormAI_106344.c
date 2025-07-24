//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10] = {2, 5, 8, 11, 13, 14, 16, 17, 18, 20};
    int searchValue = 13;
    int startIndex = 0;
    int endIndex = 9;
    int midIndex;

    printf("Welcome to the Happy Search algorithm!\n\n");
    printf("We have an array of 10 happy numbers: {2, 5, 8, 11, 13, 14, 16, 17, 18, 20}\n\n");

    while (startIndex <= endIndex) {
        midIndex = (startIndex + endIndex) / 2;
        printf("I'll check happiness at index %d first... ", midIndex);

        if (arr[midIndex] == searchValue) {
            printf("\n\nHappiness found at index %d! That's a happy day! :)\n", midIndex);
            exit(0);
        }

        printf("No happiness found here, ");

        if (arr[midIndex] < searchValue) {
            printf("I'll move on to bigger happiness...\n");
            startIndex = midIndex + 1;
        } else {
            printf("I think I need to tone it down a bit...\n");
            endIndex = midIndex - 1;
        }
    }

    printf("\nSorry, happiness value not found in our array. :( Please try searching for another number!\n");

    return 0;
}