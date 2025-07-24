//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");

    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, max = arr[0], min = arr[0];
    float avg;

    for(int i=0; i<size; i++) {
        sum += arr[i];

        if(arr[i] > max) {
            max = arr[i];
        }

        if(arr[i] < min) {
            min = arr[i];
        }
    }

    avg = (float)sum / size;

    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}