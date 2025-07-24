//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Welcome to the peaceful world of data mining!\n\n");

    // Declare the data
    int data[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int data_length = sizeof(data) / sizeof(int);

    // Calculate the average
    int sum = 0;
    for (int i = 0; i < data_length; i++) {
        sum += data[i];
    }
    double average = (double) sum / data_length;
    printf("The average value in the data set is: %.2f\n", average);

    // Calculate the standard deviation
    double deviation = 0;
    for (int i = 0; i < data_length; i++) {
        deviation += pow(data[i] - average, 2);
    }
    deviation /= data_length;
    deviation = sqrt(deviation);
    printf("The standard deviation of the data set is: %.2f\n", deviation);

    // Print the outliers
    printf("The outliers in the data set are: ");
    for (int i = 0; i < data_length; i++) {
        if (data[i] > average + deviation || data[i] < average - deviation) {
            printf("%d ", data[i]);
        }
    }

    printf("\n\nThank you for exploring the peaceful world of data mining!");
    return 0;
}