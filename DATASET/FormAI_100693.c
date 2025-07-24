//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    // generate a random list
    int data[] = {6, 9, 5, 3, 1, 2, 8, 7, 0, 4};
    int num_elements = 10;
    
    // print out the original data list
    printf("Original data list: ");
    for (int i=0; i<num_elements; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // sum the elements of the data list
    int sum = 0;
    for (int i=0; i<num_elements; i++) {
        sum += data[i];
    }
    
    // calculate the average of the data list
    float average = (float)sum / (float)num_elements;
    
    // print out the sum and average
    printf("Sum of the data list: %d\n", sum);
    printf("Average of the data list: %.2f\n", average);
    
    // perform a surreal operation
    printf("Performing surreal operation on data list...\n");
    for (int i=0; i<num_elements; i++) {
        data[i] += i;
    }
    
    // print out the modified data list
    printf("Modified data list: ");
    for (int i=0; i<num_elements; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // calculate the new sum and average
    sum = 0;
    for (int i=0; i<num_elements; i++) {
        sum += data[i];
    }
    average = (float)sum / (float)num_elements;
    
    // print out the new sum and average
    printf("Sum of the modified data list: %d\n", sum);
    printf("Average of the modified data list: %.2f\n", average);
    
    return 0;
}