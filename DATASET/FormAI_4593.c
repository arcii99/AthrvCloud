//FormAI DATASET v1.0 Category: Date and time ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100000 // size of data set
#define SAMPLES 10 // number of samples to take

int main(){
    clock_t start, end;
    double cpu_time_used;
    double data[SIZE];
    double avg, sd, var;

    srand(time(NULL));

    // generate random data set
    for(int i = 0; i < SIZE; i++){
        data[i] = (double)rand()/(double)RAND_MAX;
    }

    // perform statistical operations and calculate average time
    double total_time = 0;
    for(int i = 0; i < SAMPLES; i++){
        start = clock();

        // calculate average
        double sum = 0;
        for(int j = 0; j < SIZE; j++){
            sum += data[j];
        }
        avg = sum/SIZE;

        // calculate standard deviation
        sd = 0;
        for(int j = 0; j < SIZE; j++){
            sd += pow(data[j]-avg, 2);
        }
        sd = sqrt(sd/SIZE);

        // calculate variance
        var = pow(sd, 2);

        end = clock();

        // calculate time and add to total
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    // calculate average time and display statistical results
    double avg_time = total_time/SAMPLES;
    printf("Average Time: %.5f seconds\n", avg_time);
    printf("Average: %.5f\n", avg);
    printf("Standard Deviation: %.5f\n", sd);
    printf("Variance: %.5f\n", var);

    return 0;
}