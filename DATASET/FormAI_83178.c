//FormAI DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int size = 10;
    int* arr = (int*) malloc(sizeof(int) * size);
    int index = 0;
    
    printf("Enter the elements of the array:\n");
    
    while (1) {
        
        int num;
        scanf("%d", &num);
        
        if (num == -1) break;
        
        if (index == size) {
            size *= 2;
            arr = (int*) realloc(arr, sizeof(int) * size);
        }
        
        arr[index] = num;
        index++;
    }
    
    printf("The final array is:\n");
    
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}