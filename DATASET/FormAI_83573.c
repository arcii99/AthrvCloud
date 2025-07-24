//FormAI DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define NUM_DATA_POINTS 1000
#define NUM_FEATURES 10

// Function to generate random data points
void generate_data(float data[][NUM_FEATURES]){
    int i, j;
    float f;

    srand(time(NULL)); // Seed the random number generator

    for(i=0; i<NUM_DATA_POINTS; i++){
        for(j=0; j<NUM_FEATURES; j++){
            f = (float)rand()/(float)(RAND_MAX); // Generate a float between 0 and 1
            data[i][j] = f;
        }
    }
}

// Function to normalize the data points
void normalize_data(float data[][NUM_FEATURES]){
    int i, j;
    float sum, mean, std_dev;

    for(j=0; j<NUM_FEATURES; j++){
        sum = 0.0;
        for(i=0; i<NUM_DATA_POINTS; i++){
            sum += data[i][j];
        }
        mean = sum/NUM_DATA_POINTS;

        sum = 0.0;
        for(i=0; i<NUM_DATA_POINTS; i++){
            sum += pow((data[i][j]-mean), 2);
        }
        std_dev = sqrt(sum/NUM_DATA_POINTS);

        for(i=0; i<NUM_DATA_POINTS; i++){
            data[i][j] = (data[i][j]-mean)/std_dev;
        }
    }
}

// Function to calculate the distance between two data points
float distance(float point1[], float point2[]){
    int i;
    float sum = 0.0;

    for(i=0; i<NUM_FEATURES; i++){
        sum += pow((point1[i]-point2[i]), 2);
    }

    return sqrt(sum);
}

// Main function
int main(){
    float data[NUM_DATA_POINTS][NUM_FEATURES];
    float new_point[NUM_FEATURES], nearest_point[NUM_FEATURES];
    float min_dist = 999999.0, dist;
    int i, j, nearest_index = 0;

    // Generate some random data points
    generate_data(data);

    // Normalize the data points
    normalize_data(data);

    // Generate a new random data point
    for(i=0; i<NUM_FEATURES; i++){
        new_point[i] = (float)rand()/(float)(RAND_MAX); // Generate a float between 0 and 1
    }

    // Find the nearest data point to the new point
    for(i=0; i<NUM_DATA_POINTS; i++){
        dist = distance(new_point, data[i]);
        if(dist < min_dist){
            min_dist = dist;
            nearest_index = i;
        }
    }

    // Set the nearest point to the new point
    for(j=0; j<NUM_FEATURES; j++){
        nearest_point[j] = new_point[j];
        data[nearest_index][j] = new_point[j];
    }

    // Print out the nearest data point and the new point
    printf("The nearest data point is:\n");
    for(j=0; j<NUM_FEATURES; j++){
        printf("%.2f ", data[nearest_index][j]);
    }
    printf("\n");

    printf("The new data point is:\n");
    for(j=0; j<NUM_FEATURES; j++){
        printf("%.2f ", new_point[j]);
    }
    printf("\n");

    return 0;
}