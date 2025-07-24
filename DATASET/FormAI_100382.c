//FormAI DATASET v1.0 Category: Scientific ; Style: portable
/*This is a program that calculates the Average, Maximum, and Minimum values of a set of numbers*/

#include <stdio.h>

int main() {
    int n, i;
    float num[100], sum = 0.0, average, max, min;

    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    //Reading Input
    for(i=0; i<n; ++i) {
        printf("Enter Number %d: ", i+1);
        scanf("%f", &num[i]);
        sum += num[i];
    }

    //Calculating Average
    average = sum/n;
    printf("\nAverage = %.2f\n", average);

    //Finding Maximum Value
    max = num[0];
    for(i=0; i<n; i++) {
        if(max < num[i])
            max = num[i];
    }
    printf("Maximum = %.2f\n", max);

    //Finding Minimum Value
    min = num[0];
    for(i=0; i<n; i++) {
        if(min > num[i])
            min = num[i];
    }
    printf("Minimum = %.2f\n", min);

    return 0;
}