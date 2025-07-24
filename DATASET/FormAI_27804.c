//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>

int main() {
    int n;
    float sum=0.0, mean, sd=0.0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float arr[n];

    for(int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    mean = sum/n;

    for(int i=0; i<n; i++) {
        sd += pow(arr[i]-mean, 2);
    }
    sd = sqrt(sd/n);

    printf("\nEntered elements are: ");
    for(int i=0; i<n; i++) {
        printf("%f ", arr[i]);
    }

    printf("\nSum of the elements: %f", sum);
    printf("\nMean: %f", mean);
    printf("\nStandard Deviation: %f", sd);

    return 0;
}