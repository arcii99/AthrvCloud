//FormAI DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[10] = {3, 6, 8, 2, 1, 9, 4, 5, 7, 0};
    int min, max;

    // Finding the minimum element in the array
    min = data[0];
    for(int i = 1; i < 10; i++){
        if(min > data[i]){
            min = data[i];
        }
    }
    printf("The minimum element in the array is %d\n", min);

    // Finding the maximum element in the array
    max = data[0];
    for(int i = 1; i < 10; i++){
        if(max < data[i]){
            max = data[i];
        }
    }
    printf("The maximum element in the array is %d\n", max);

    // Finding the mean of the elements in the array
    float sum = 0;
    for(int i = 0; i < 10; i++){
        sum += data[i];
    }
    float mean = sum / 10;
    printf("The mean of the elements in the array is %f\n", mean);

    // Finding the median of the elements in the array
    int median;
    int temp;
    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(data[j] < data[i]){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    if(10 % 2 == 0){
        median = (data[10/2] + data[10/2 - 1]) / 2;
    }
    else{
        median = data[10/2];
    }
    printf("The median of the elements in the array is %d\n", median);

    return 0;
}