//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Print a peaceful greeting message
    printf("Welcome to the Peaceful Data Mining Program\n");

    // Define an array to hold the data
    int data[10] = {5, 6, 2, 9, 1, 4, 8, 3, 7, 0};
    
    // Define some variables to hold the results
    int min_value = data[0];
    int max_value = data[0];
    float mean_value = 0.0;
    int sum_value = 0;
    
    // Loop through the data to find the min, max, and sum
    for(int i=0; i<10; i++) {
        if(data[i] < min_value) {
            min_value = data[i];
        }
        if(data[i] > max_value) {
            max_value = data[i];
        }
        sum_value += data[i];
    }
    
    // Calculate the mean value
    mean_value = (float) sum_value / 10;
    
    // Print out the results
    printf("The data is: ");
    for(int i=0; i<10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("The minimum value is: %d\n", min_value);
    printf("The maximum value is: %d\n", max_value);
    printf("The sum of the data is: %d\n", sum_value);
    printf("The mean value of the data is: %f\n", mean_value);
    
    // Say a peaceful goodbye message
    printf("Thank you for using the Peaceful Data Mining Program\n");
    
    return 0;
}