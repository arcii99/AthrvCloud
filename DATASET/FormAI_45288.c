//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include<stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int sum = 0, avg;
    for(int i=0; i < 5; i++) {
        sum += arr[i];
    }
    avg = sum / 5;
    printf("The sum of the elements in the array is %d\n", sum);
    printf("The average of the elements in the array is %d\n", avg);
    return 0;
}