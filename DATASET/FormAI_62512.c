//FormAI DATASET v1.0 Category: Benchmarking ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, k, sum;
    double time_taken;
    clock_t t;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n][n], brr[n][n], crr[n][n];

    //Generate random elements for matrices arr and brr
    srand(time(NULL));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]= rand()%100;
            brr[i][j]= rand()%100;
        }
    }

    //Matrix Multiplication Algorithm
    t = clock();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum=0;
            for(k=0;k<n;k++){
                sum+=arr[i][k]*brr[k][j];
            }
            crr[i][j]=sum;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;

    //Display Resulting matrix crr and the time taken to multiply matrices arr and brr
    printf("Resulting matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           printf("%d  ", crr[i][j]); 
        }
        printf("\n");
    }
    printf("Time taken: %lf seconds", time_taken);

    return 0;
}