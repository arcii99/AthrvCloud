//FormAI DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    
    printf("The original array is: [ ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    printf("The sum of the elements in the array is: %d\n", sum);
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    
    printf("The reversed array is: [ ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    return 0;
}