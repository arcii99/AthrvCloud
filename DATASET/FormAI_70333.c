//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10] = {3, 2, 5, 1, 7, 6, 8, 9, 4, 10};
    int i, j, temp;
    float mean, variance, std_deviation = 0;

    // calculate mean
    for(i = 0; i < 10; i++){
        mean += arr[i];
    }
    mean /= 10;

    // calculate variance
    for(i = 0; i < 10; i++){
        variance += pow(arr[i] - mean, 2);
    }
    variance /= 10;

    // calculate standard deviation
    std_deviation = sqrt(variance);

    // sort array in ascending order
    for(i = 0; i < 10; i++){
        for(j = i+1; j < 10; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // print sorted array
    printf("Data after sorting:\n");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    // print mean, variance and standard deviation
    printf("\nMean = %.2f", mean);
    printf("\nVariance = %.2f", variance);
    printf("\nStandard Deviation = %.2f", std_deviation);

    return 0;
}