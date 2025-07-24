//FormAI DATASET v1.0 Category: Digital signal processing ; Style: synchronous
#include<stdio.h>

//function to calculate the dot product of two arrays
int dot_product(int x[], int y[], int n){
    int result = 0;
    for(int i=0; i<n; i++){
        result += x[i]*y[i];
    }
    return result;
}

//function to calculate the convolution of two arrays
void convolution(int x[], int h[], int y[], int n, int m){
    for(int i=0; i<n+m-1; i++){
        int start_index = (i>=m-1)? i-m+1 : 0;
        int end_index = (i<n-1)? i+1 : n;
        for(int j=start_index; j<end_index; j++){
            y[i] += x[j]*h[i-j];
        }
    }
}

int main(){
    int x[] = {1, 2, 3, 4, 5};
    int h[] = {5, 4, 3, 2, 1};
    int n = 5;
    int m = 5;
    int y[n+m-1];
    for(int i=0; i<n+m-1; i++){
        y[i] = 0;
    }
    
    //print inputs
    printf("Input sequence x[n]: ");
    for(int i=0; i<n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    printf("Impulse response h[n]: ");
    for(int i=0; i<m; i++){
        printf("%d ", h[i]);
    }
    printf("\n");
    
    //calculate dot product and print
    int dot_prod = dot_product(x, h, n);
    printf("Dot product of x[n] and h[n]: %d\n", dot_prod);
    
    //calculate convolution and print
    convolution(x, h, y, n, m);
    printf("Convolution of x[n] and h[n]: ");
    for(int i=0; i<n+m-1; i++){
        printf("%d ", y[i]);
    }
    printf("\n");
    
    return 0;
}