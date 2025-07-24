//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Data set
    int data[10][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24},
        {25, 26, 27},
        {28, 29, 30}
    };

    // Calculate the average of each column
    float avg[3] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            avg[j] += data[i][j];
        }
    }
    for(int j = 0; j < 3; j++){
        avg[j] /= 10;
    }

    // Calculate the standard deviation of each column
    float stddev[3] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            stddev[j] += (data[i][j] - avg[j]) * (data[i][j] - avg[j]);
        }
    }
    for(int j = 0; j < 3; j++){
        stddev[j] = sqrt(stddev[j] / 10);
    }

    // Output the results
    printf("Data set:\n");
    for(int i = 0; i < 10; i++){
        printf("%d %d %d\n", data[i][0], data[i][1], data[i][2]);
    }
    printf("Average:\n");
    printf("%f %f %f\n", avg[0], avg[1], avg[2]);
    printf("Standard deviation:\n");
    printf("%f %f %f\n", stddev[0], stddev[1], stddev[2]);

    return 0;
}