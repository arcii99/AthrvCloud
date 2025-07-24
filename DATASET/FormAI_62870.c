//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
// A dynamic program to calculate the average of user inputted integers

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    float sum = 0;

    printf("Enter the number of integers you want to average: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));

    printf("Enter %d integers: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    float average = sum / size;
    printf("The average of the %d integers is %.2f", size, average);

    free(arr); // free up memory allocated by malloc
    
    return 0;
}