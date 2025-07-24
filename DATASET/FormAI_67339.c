//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include<stdio.h>

//Function to add two matrices
void add_matrices(int r1, int c1, int A[][c1], int B[][c1])
{
    int C[r1][c1]; //resultant matrix
    
    //performing addition operation on matrices A and B
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            C[i][j]=A[i][j]+B[i][j];
        }        
    }
    
    //printing resultant matrix
    printf("Resultant matrix after addition is:\n");
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            printf("%d\t", C[i][j]);
        }        
        printf("\n");
    }
}


//Function to multiply two matrices
void multiply_matrices(int r1, int c1, int r2, int c2, int A[][c1], int B[][c2])
{
    int C[r1][c2]; //resultant matrix
    
    //performing multiplication operation on matrices A and B
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c2;++j)
        {
            C[i][j]=0;
            for(int k=0;k<c1;++k)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }        
    }
    
    //printing resultant matrix
    printf("Resultant matrix after multiplication is:\n");
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c2;++j)
        {
            printf("%d\t", C[i][j]);
        }        
        printf("\n");
    }
}


int main()
{
    int r1,c1,r2,c2;
    printf("Enter dimensions of matrix A (row col): ");
    scanf("%d%d",&r1,&c1);
    printf("Enter dimensions of matrix B (row col): ");
    scanf("%d%d",&r2,&c2);
    
    if(c1!=r2)
    {
        printf("Matrices cannot be multiplied");
        return 0;
    }
    
    int A[r1][c1]; //matrix A
    int B[r2][c2]; //matrix B
    
    //taking input for matrix A
    printf("Enter values for matrix A:\n");
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            scanf("%d", &A[i][j]);
        }        
    }
    
    //taking input for matrix B
    printf("Enter values for matrix B:\n");
    for(int i=0;i<r2;++i)
    {
        for(int j=0;j<c2;++j)
        {
            scanf("%d", &B[i][j]);
        }    
    }
    
    //performing addition operation on matrices A and B
    add_matrices(r1,c1,A,B);
    
    //performing multiplication operation on matrices A and B
    multiply_matrices(r1,c1,r2,c2,A,B);
    
    return 0;
}