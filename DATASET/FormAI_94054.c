//FormAI DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the invasive data mining program! \n");

    // Create our dataset
    int data[10] = {23, 18, 14, 32, 46, 19, 27, 41, 52, 37};
    int sum = 0;

    // Display the original dataset
    printf("The original dataset is: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }

    // Calculate the sum of the dataset to identify any outliers
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }

    // Determine the mean of the dataset
    float mean = sum / 10.0;

    // Identify any outliers
    printf("\nThe outliers in the dataset are: \n");
    for (int i = 0; i < 10; i++) {
        if (data[i] > (mean + 10)) {  // If the data point is more than 10 units away from the mean
            printf("%d ", data[i]);  // Print the outlier
        }
    }

    // Sort the dataset in ascending order
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (data[i] > data[j]) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    // Display the sorted dataset
    printf("\nThe sorted dataset is: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }

    // Calculate the median of the dataset
    float median;
    if (10 % 2 == 0) {  // If the dataset has an even number of elements
        median = (data[(10/2)-1] + data[(10/2)]) / 2.0;  // Calculate the average of the two middle values
    } else {  // If the dataset has an odd number of elements
        median = data[10/2];  // Set the median to the middle value
    }
    printf("\nThe median of the dataset is: %.1f", median);
    
    printf("\nThank you for using the invasive data mining program!");
    return 0;
}