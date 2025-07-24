//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variables initialization
    int data[] = {10,20,30,40,50,60,70};
    int size = sizeof(data)/sizeof(int);
    int sum = 0;
    float mean;
    int max = data[0];
    int min = data[0];

    // Calculating the sum, mean, max and min of the data
    for(int i=0; i<size; i++) {
        sum += data[i];
        if(data[i] > max) {
            max = data[i];
        }
        if(data[i] < min) {
            min = data[i];
        }
    }
    mean = (float)sum/size;

    // Outputting the results
    printf("Data set: ");
    for(int i=0; i<size; i++) {
        printf("%d ", data[i]);
    }
    printf("\nSum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}