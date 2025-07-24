//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <time.h>

int main() {
    int matrix1[1000][1000], matrix2[1000][1000], result[1000][1000];
    int i, j, k;
    clock_t start, end;
    double time_taken;

    // Initialize the matrices randomly
    for(i=0;i<1000;i++) {
        for(j=0;j<1000;j++) {
            matrix1[i][j] = rand();
            matrix2[i][j] = rand();
        }
    }

    // Perform matrix multiplication and measure time taken
    start = clock();
    for(i=0;i<1000;i++) {
        for(j=0;j<1000;j++) {
            for(k=0;k<1000;k++) {
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    // Print the result matrix and time taken for multiplication
    printf("Resultant Matrix:\n");
    for(i=0;i<1000;i++) {
        for(j=0;j<1000;j++) {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    printf("Time taken: %f seconds", time_taken);

    return 0;
}