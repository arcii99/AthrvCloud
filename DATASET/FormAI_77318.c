//FormAI DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

double average(double array[], int size) {
    double sum = 0;
    for (int i=0; i<size; i++) {
        sum += array[i];
    }
    return sum/size;
}

double standard_deviation(double array[], int size) {
    double mean = average(array, size);
    double variance = 0;
    for (int i=0; i<size; i++) {
        variance += pow((array[i]-mean), 2);
    }
    return sqrt(variance/size);
}

int compare(const void *a, const void *b) {
    double x = *(double*)a;
    double y = *(double*)b;
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

double median(double array[], int size) {
    qsort(array, size, sizeof(double), compare);
    if (size % 2 == 0) {
        return (array[size/2-1] + array[size/2]) / 2.0;
    } else {
        return array[size/2];
    }
}

double max(double array[], int size) {
    double max_val = array[0];
    for (int i=1; i<size; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }
    return max_val;
}

double min(double array[], int size) {
    double min_val = array[0];
    for (int i=1; i<size; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }
    return min_val;
}

int main() {
    double data[SIZE];
    srand(time(NULL));
    for (int i=0; i<SIZE; i++) {
        data[i] = (double)rand()/RAND_MAX*100;
    }
    printf("Average: %f\n", average(data, SIZE));
    printf("Standard Deviation: %f\n", standard_deviation(data, SIZE));
    printf("Median: %f\n", median(data, SIZE));
    printf("Maximum value: %f\n", max(data, SIZE));
    printf("Minimum value: %f\n", min(data, SIZE));
    return 0;
}