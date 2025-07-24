//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include<stdio.h>

int main(){
    // creating sample dataset
    int data[] = {5, 9, 2, 4, 7, 1, 3, 6, 8};
    int size = sizeof(data)/sizeof(data[0]);
    
    // printing the dataset
    printf("Sample dataset: ");
    for(int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    
    printf("\n\n");

    // Finding the smallest number in the dataset
    int smallest = data[0];
    for(int i=1; i<size; i++){
        if(data[i]<smallest){
            smallest = data[i];
        }
    }

    printf("The smallest number in the dataset is: %d \n", smallest);

    // Finding the largest number in the dataset
    int largest = data[0];
    for(int i=1; i<size; i++){
        if(data[i]>largest){
            largest = data[i];
        }
    }

    printf("The largest number in the dataset is: %d \n", largest);


    // Finding the sum of all numbers in the dataset
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += data[i];
    }

    printf("The sum of all numbers in the dataset is: %d \n", sum);

    // Finding the average of all numbers in the dataset
    float avg = (float)sum/size;

    printf("The average of all numbers in the dataset is: %.2f \n", avg);

    return 0;
}