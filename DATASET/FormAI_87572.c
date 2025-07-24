//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Data set for analysis
    int data[] = {23, 19, 16, 18, 22, 21, 15, 20, 17, 23, 24, 19, 18, 25, 16, 22, 17, 20, 19, 21};

    // Find the size of the data set
    int size = sizeof(data)/sizeof(data[0]);

    // Calculate the average of the data set
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }

    float average = sum/size;

    // Calculate the standard deviation of the data set
    sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += pow(data[i] - average, 2);
    }

    float standard_deviation = sqrt(sum/(size-1));
    
    // Display the results
    printf("Data set: { ");
    for(int i = 0; i < size; ++i) {
        printf("%d ", data[i]);
    }
    printf("}\n");
    printf("Average: %.2f\n", average);
    printf("Standard deviation: %.2f\n", standard_deviation);

    return 0;
}