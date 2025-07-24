//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#define MAX 10        // maximum size of the matrix
 
void printMatrix(int arr[MAX][MAX],int row,int col){
    printf("\nMatrix Printed: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
 
void addMatrix(int arr1[MAX][MAX],int arr2[MAX][MAX],int res[MAX][MAX],int row,int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\nAdded Matrix: \n");
    printMatrix(res,row,col);
}
 
void subMatrix(int arr1[MAX][MAX],int arr2[MAX][MAX],int res[MAX][MAX],int row,int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("\nSubtracted Matrix: \n");
    printMatrix(res,row,col);
}
 
void multiplyMatrix(int arr1[MAX][MAX],int arr2[MAX][MAX],int res[MAX][MAX],int r1,int c1,int c2){
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            res[i][j] = 0;
            for(int k=0; k<c1; k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nMultiplied Matrix: \n");
    printMatrix(res,r1,c2);
}
 
int main(){
    int arr1[MAX][MAX],arr2[MAX][MAX],res[MAX][MAX],r1,r2,c1,c2,choice;
    printf("Enter the size of the first matrix (rows x columns): ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the elements of the first matrix: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d",&arr1[i][j]);
        }
    }
 
    printf("\nEnter the size of the second matrix (rows x columns): ");
    scanf("%d %d",&r2,&c2);
    printf("Enter the elements of the second matrix: \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d",&arr2[i][j]);
        }
    }
 
    printf("\nThe first matrix is: \n");
    printMatrix(arr1,r1,c1);
 
    printf("\nThe second matrix is: \n");
    printMatrix(arr2,r2,c2);
 
    printf("\nSelect the Operation to Perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
 
    switch(choice){
        case 1: if(r1!=r2 || c1!=c2){
                    printf("\nERROR: The Matrices cannot be Added!\n");
                }
                else{
                    addMatrix(arr1,arr2,res,r1,c1);
                }
                break;
 
        case 2: if(r1!=r2 || c1!=c2){
                    printf("\nERROR: The Matrices cannot be Subtracted!\n");
                }
                else{
                    subMatrix(arr1,arr2,res,r1,c1);
                }
                break;
 
        case 3: if(c1!=r2){
                    printf("\nERROR: The Matrices cannot be Multiplied!\n");
                }
                else{
                    multiplyMatrix(arr1,arr2,res,r1,c1,c2);
                }
                break;
 
        default:printf("\nERROR: Invalid Choice! Please Enter a Valid Choice.\n");
    }
    return 0;
}