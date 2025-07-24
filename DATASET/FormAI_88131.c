//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, *ptr, sum = 0;

    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("The elements you entered are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr+i));
    }

    printf("\nThe sum of the elements is: %d", sum);

    free(ptr); //deallocating the memory

    return 0;
}