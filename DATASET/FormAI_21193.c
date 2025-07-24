//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>

int main() {
    
    int arr[5][5];
    int i, j, sum = 0;
    float average;
    
    printf("Enter 5 x 5 array elements:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    average = (float)sum/(5*5);

    printf("\nAverage value of all array elements : %.2f", average);
    printf("\nElements that are above the average :");
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(arr[i][j] > average) {
                printf(" %d,", arr[i][j]);
            }
        }
    }
    
    return 0;
}