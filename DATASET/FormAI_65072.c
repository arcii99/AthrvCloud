//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(){
    int i, j, temp, data[ARRAY_SIZE];
    double time_taken;
    clock_t start, end;

    // Generate random data
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++){
        data[i] = rand() % 1000;
    }

    // Bubble Sort
    start = clock();
    for(i = 0; i < ARRAY_SIZE - 1; i++){
        for(j = 0; j < ARRAY_SIZE - i - 1; j++){
            if(data[j] > data[j + 1]){
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort time taken: %f seconds\n", time_taken);

    // Selection Sort
    start = clock();
    for(i = 0; i < ARRAY_SIZE - 1; i++){
        int min_index = i;
        for(j = i + 1; j < ARRAY_SIZE; j++){
            if(data[j] < data[min_index]){
                min_index = j;
            }
        }
        temp = data[i];
        data[i] = data[min_index];
        data[min_index] = temp;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort time taken: %f seconds\n", time_taken);

    // Insertion Sort
    start = clock();
    for(i = 1; i < ARRAY_SIZE; i++){
        temp = data[i];
        j = i - 1;
        while(j >= 0 && data[j] > temp){
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort time taken: %f seconds\n", time_taken);

    return 0;
}