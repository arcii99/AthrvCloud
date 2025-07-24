//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, x;
    int array[10] = {0};
    srand(time(NULL));
    
    printf("Generating 10 random numbers:\n");
    
    for(i = 0; i < 10; i++) {
        x = rand() % 100 + 1;
        array[i] = x;
        printf("%d ", x);
    }
    
    printf("\n\nSorting in ascending order:\n");
    
    for(i = 0; i < 9; i++) {
        int j, minIndex = i;
        for(j = i + 1; j < 10; j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
    
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n\nCalculating statistical measures:\n");
    
    int sum = 0;
    for(i = 0; i < 10; i++) {
        sum += array[i];
    }
    float mean = sum / 10.0;
    printf("Mean: %.2f\n", mean);
    
    int median;
    if(10 % 2 == 0) {
        median = (array[4] + array[5]) / 2;
    } else {
        median = array[5];
    }
    printf("Median: %d\n", median);
    
    int range = array[9] - array[0];
    printf("Range: %d\n", range);
    
    float variance = 0;
    for(i = 0; i < 10; i++) {
        variance += ((array[i] - mean) * (array[i] - mean));
    }
    variance /= 9;
    printf("Variance: %.2f\n", variance);
    
    float standardDeviation = sqrt(variance);
    printf("Standard deviation: %.2f\n", standardDeviation);
    
    return 0;
}