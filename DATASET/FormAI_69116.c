//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int data[] = {45, 94, 26, 31, 89, 67, 72, 15, 18, 53, 78, 39, 63, 57, 81, 29, 12, 42, 88, 48, 76, 22, 66, 35, 60, 91, 17, 55, 20, 84, 73, 46, 69, 27, 51, 98, 24, 80, 61, 13, 36, 87, 32, 79, 58, 43, 16, 50, 90, 71, 38, 75, 25, 49, 21, 68, 40, 56, 33, 77, 85, 14, 70, 54, 97, 23, 44, 82, 28, 65, 30, 19, 83, 62, 47, 95, 10, 41, 86, 34, 99, 52, 37, 11, 64, 92, 96, 59, 74};
    
    int *even_numbers = (int*)malloc(sizeof(int)*50);
    int *odd_numbers = (int*)malloc(sizeof(int)*50);
    int even_count = 0;
    int odd_count = 0;

    for(int i=0; i<100; i++){
        if(data[i] % 2 == 0){
            even_numbers[even_count] = data[i];
            even_count++;
        }
        else{
            odd_numbers[odd_count] = data[i];
            odd_count++;
        }
    }

    printf("The even numbers are:\n");

    for(int i=0; i<even_count; i++){
        printf("%d\n", even_numbers[i]);
    }
    printf("The odd numbers are:\n");

    for(int i=0; i<odd_count; i++){
        printf("%d\n", odd_numbers[i]);
    }

    free(even_numbers);
    free(odd_numbers);
    return 0;
}