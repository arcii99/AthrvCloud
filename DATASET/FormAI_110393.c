//FormAI DATASET v1.0 Category: Sorting ; Style: excited
//Wow, let's sort some numbers!
//I am so excited about this sorting program!
#include <stdio.h>

int main() {

    //First, let's declare our array of numbers
    int numbers[] = {12, 45, 3, 67, 89, 23, 56, 11};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    //Before sorting
    printf("Before sorting:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    //Now let's sort the numbers using bubble sort
    //This is going to be so much fun!
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(numbers[j] > numbers[j+1]) {
                //Swap numbers
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    //After sorting
    printf("After sorting:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    //Wohoo, we did it!
    printf("That was so much fun sorting these numbers!\n");

    return 0;
}