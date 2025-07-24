//FormAI DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a data structure for our dataset, containing two integers
typedef struct {
    int x;
    int y;
} data_point;

// Defining a function to print out the contents of a data_point
void print_data_point(data_point point) {
    printf("(%i,%i)", point.x, point.y);
}

int main() {
    // Create an array to hold our data points
    data_point data[10];

    // Fill the array with random data points
    for (int i = 0; i < 10; i++) {
        data[i].x = rand() % 100;
        data[i].y = rand() % 100;
    }

    // Print the initial dataset
    printf("Initial dataset: ");
    for (int i = 0; i < 10; i++) {
        print_data_point(data[i]);
        printf(" ");
    }
    printf("\n");

    // Find the data point with the highest x value
    data_point max_x = data[0];
    for (int i = 1; i < 10; i++) {
        if (data[i].x > max_x.x) {
            max_x = data[i];
        }
    }

    // Print the data point with the highest x value
    printf("Data point with highest x value: ");
    print_data_point(max_x);
    printf("\n");

    // Find the data point with the highest y value
    data_point max_y = data[0];
    for (int i = 1; i < 10; i++) {
        if (data[i].y > max_y.y) {
            max_y = data[i];
        }
    }

    // Print the data point with the highest y value
    printf("Data point with highest y value: ");
    print_data_point(max_y);
    printf("\n");

    // Calculate the average x and y values
    int total_x = 0;
    int total_y = 0;
    for (int i = 0; i < 10; i++) {
        total_x += data[i].x;
        total_y += data[i].y;
    }
    double avg_x = (double)total_x / 10;
    double avg_y = (double)total_y / 10;

    // Print the average x and y values
    printf("Average x value: %f\n", avg_x);
    printf("Average y value: %f\n", avg_y);

    return 0;
}