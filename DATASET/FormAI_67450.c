//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //initializing random seed
    
    int n, i, j, sum=0, counter=0;
    
    printf("Enter the number of rows/columns for a square matrix: ");
    scanf("%d", &n); //taking input for matrix size
    
    int matrix[n][n]; //declaring a 2D array to store the matrix elements
    printf("Enter the elements of the matrix:\n");
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrix[i][j]); //taking input for matrix elements
        }
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            sum+=matrix[i][j]; //calculating the sum of matrix elements
            counter++; //incrementing the counter for each element
        }
    }
    
    printf("The entered matrix is:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix[i][j]); //displaying the entered matrix
        }
        printf("\n");
    }
    
    printf("\nThe sum of all the elements in the matrix is %d\n", sum);
    printf("The average of all the elements in the matrix is %.2f\n", (float)sum/counter);
    
    //code for finding the maximum and minimum element in the matrix
    int max=matrix[0][0], min=matrix[0][0];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(matrix[i][j]>max) max=matrix[i][j];
            if(matrix[i][j]<min) min=matrix[i][j];
        }
    }
    
    printf("The maximum element in the matrix is %d\n", max);
    printf("The minimum element in the matrix is %d\n", min);
    
    //code for finding the frequency of all the elements in the matrix
    int frequency[100]={0};
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            frequency[matrix[i][j]]++; //incrementing the counter for each element
        }
    }
    
    printf("\nThe frequency of all the elements in the matrix is:\n");
    for(i=min; i<=max; i++){
        if(frequency[i]>0){
            printf("%d occurs %d times\n", i, frequency[i]); //displaying the frequency of each element
        }
    }
    
    return 0;
}