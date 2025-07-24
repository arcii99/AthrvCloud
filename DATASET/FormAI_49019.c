//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>

int main() {
    int data[] = {5, 8, 3, 6, 2, 9, 1, 4, 7}; // Our data set
    int n = sizeof(data) / sizeof(int); //Calculating the size of data set
    int sum = 0;
    double mean;
    int max = data[0];
    int min = data[0];
    
    //Finding the sum of all elements in the data set
    for(int i=0; i<n; i++) {
        sum += data[i];
    }
    
    //Finding the mean of all elements in the data set
    mean = (double) sum / n;
    
    //Finding the maximum and minimum values in the data set
    for(int i=1; i<n; i++) {
        if(data[i] > max) {
            max = data[i];
        }
        if(data[i] < min) {
            min = data[i];
        }
    }
    
    //Printing the results
    printf("Data set: ");
    for(int i=0; i<n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", mean);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    
    return 0;
}