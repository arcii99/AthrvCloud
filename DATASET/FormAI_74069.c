//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to our memory management program!\n");
    printf("We will allocate some dynamic memory for you...\n");
    
    int *numbers = (int*) malloc(5 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed, sorry!\n");
        return 1;
    }
    
    printf("Enter five numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    
    printf("The numbers you entered are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Now let's increase the size of the dynamic memory...\n");
    int *more_numbers = (int*) realloc(numbers, 10 * sizeof(int));
    if (more_numbers == NULL) {
        printf("Memory reallocation failed, sorry!\n");
        return 1;
    }
    
    numbers = more_numbers;
    
    printf("Enter five more numbers:\n");
    for (int i = 5; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }
    
    printf("The numbers you entered are: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    free(numbers);
    printf("Memory has been freed!\n");
    
    return 0;
}