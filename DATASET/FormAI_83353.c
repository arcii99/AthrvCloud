//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Alan Touring
// Alan Turing Style Example C Program for Digital Signal Processing

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265

int main(){
    float x[100],y[100],z[100],a,b,c;
    int i,j,n;

    printf("Enter the number of data points: ");
    scanf("%d",&n);

    printf("Enter the values of x: ");
    for(i=0;i<n;i++){
        scanf("%f",&x[i]);
    }

    printf("Enter the values of y: ");
    for(j=0;j<n;j++){
        scanf("%f",&y[j]);
    }

    printf("Enter the values of z: ");
    for(i=0;i<n;i++){
        scanf("%f",&z[i]);
    }

    for(i=0;i<n;i++){
        a = sin(x[i]*PI/180);
        b = cos(y[i]*PI/180);
        c = pow(z[i],2);

        printf("The values after signal processing for data point %d is: a = %f, b = %f, c = %f\n",i+1,a,b,c);
    }

    return 0;
}