//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, max = 0;
    srand(time(NULL));
    
    printf("Enter length of sequence: ");
    scanf("%d", &n);
    
    int *sequence = (int*) malloc(n * sizeof(int)); // dynamic memory allocation
    
    // generate random sequence of numbers between 1 and 100
    for (i = 0; i < n; i++) {
        sequence[i] = rand() % 100 + 1;
        printf("%d ", sequence[i]);
        
        if (sequence[i] > max) {
            max = sequence[i];
        }
    }
    
    printf("\n\nThe largest number in the sequence is: %d", max);
  
    free(sequence); // free memory
    
    return 0;
}