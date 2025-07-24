//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i, j, k, m;
    float x[100], y[100], z[100], a, b, c, area;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the points:\n");
    for(i=0; i<n; i++){
        scanf("%f%f%f", &x[i], &y[i], &z[i]);
    }

    printf("\nTriangle\t\tArea\n");

    for(i=0; i<n-2; i++){
        for(j=i+1; j<n-1; j++){
            for(k=j+1; k<n; k++){
                a = sqrt(pow(x[j]-x[i], 2) + pow(y[j]-y[i], 2) + pow(z[j]-z[i], 2));
                b = sqrt(pow(x[k]-x[j], 2) + pow(y[k]-y[j], 2) + pow(z[k]-z[j], 2));
                c = sqrt(pow(x[k]-x[i], 2) + pow(y[k]-y[i], 2) + pow(z[k]-z[i], 2));

                if((a+b>c) && (a+c>b) && (b+c>a)){
                    float s = (a+b+c)/2;
                    area = sqrt(s*(s-a)*(s-b)*(s-c));
                    printf("Triangle %d %d %d\t%.2f\n", i+1, j+1, k+1, area);
                }
            }
        }
    }

    return 0;
}