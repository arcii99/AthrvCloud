//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

/* 
Fractal generation code in medieval style 
*/ 

/* Function to initialize values of array */
void initializeArray(double **arr,int n){
  int i, j; 
  for(i=0;i<n;i++){
    arr[i]=(double*)malloc(n*sizeof(double)); 
    for(j=0;j<n;j++){
      arr[i][j]=0; 
    }
  }
}

/* Function to free array */
void freeArray(double **arr,int n){
  int i; 
  for (i = 0; i < n; i++) {
        free(arr[i]);
  }
  free(arr);
}

/* Function to generate fractal */
void generateFractal(double **arr, int n, int level){
    if(level==0){
        arr[0][0]=arr[0][n-1]=arr[n-1][0]=arr[n-1][n-1]=1; 
        return; 
    }
    int side=n/pow(3,level-1); 
    generateFractal(arr,n,level-1); 
    int i,j; 
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==1&&j==1) continue; 
            int ii=i*side,jj=j*side; 
            int k,l; 
            for(k=ii;k<ii+side;k++){
                for(l=jj;l<jj+side;l++){
                    arr[k][l]=arr[k-side][l-side]; 
                }
            }
        }
    }
    int ii=i*side,jj=j*side; 
    int k; 
    for(k=ii;k<ii+side;k++){
        arr[k][jj+side]=arr[k][jj-side];
    }
    int l;
    for(l=jj;l<jj+side;l++){
        arr[ii+side][l]=arr[ii-side][l]; 
    }
}

int main() 
{ 
    int n,level ; 
    printf("Enter the value of n:"); 
    scanf("%d",&n); 
    printf("\nEnter the level:"); 
    scanf("%d",&level); 
    
    double **arr=(double**)malloc(n*sizeof(double*)); 
    initializeArray(arr,n); 
    
    generateFractal(arr,n,level); 
    
    int i,j; 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==1){
                printf("*");
            }
            else{
                printf(" "); 
            }
        }
        printf("\n"); 
    }
    
    freeArray(arr,n); 
    return 0; 
}