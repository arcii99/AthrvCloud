//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>

int main() {
    int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Initializing the array
    int sum = 0; // Initializing a variable to hold the sum
    
    // Printing the original array
    printf("Original array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Calculating and printing the sum of even elements
    printf("Sum of even elements: ");
    for(int i = 0; i < 10; i++) {
        if(array[i] % 2 == 0) {
            sum += array[i];
        }
    }
    printf("%d\n", sum);
    
    // Reversing the array
    int temp;
    for(int i = 0, j = 9; i < j; i++, j--) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    // Printing the reversed array
    printf("Reversed array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Separating even and odd elements
    int even[10], odd[10];
    int evenCount = 0, oddCount = 0;
    for(int i = 0; i < 10; i++) {
        if(array[i] % 2 == 0) {
            even[evenCount] = array[i];
            evenCount++;
        } else {
            odd[oddCount] = array[i];
            oddCount++;
        }
    }
    
    // Printing the even and odd arrays
    printf("Even elements: ");
    for(int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    printf("Odd elements: ");
    for(int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");
    
    return 0;
}