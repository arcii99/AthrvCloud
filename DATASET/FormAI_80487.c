//FormAI DATASET v1.0 Category: Math exercise ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j;
    float x, y, sum=0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            x = pow(i, j);
            y = pow(j, i);
            sum += x/y;
        }
    }
    printf("The sum of the series is: %f", sum);
    return 0;
}