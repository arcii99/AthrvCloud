//FormAI DATASET v1.0 Category: Matrix operations ; Style: romantic
#include<stdio.h>

int main(){

int rowA, colA, rowB, colB, i, j;
int A[50][50], B[50][50], sum[50][50];

printf("Enter the number of rows and columns of matrix A: ");
scanf("%d %d",&rowA, &colA);

printf("Enter the number of rows and columns of matrix B: ");
scanf("%d %d",&rowB, &colB);

if(colA!=rowB){

printf("\n Matrix multiplication is not possible. ");

}
else {

printf("\nEnter elements of matrix A: \n");

for(i=0; i<rowA; i++){
for(j=0; j<colA; j++){
scanf("%d",&A[i][j]);
}
}

printf("\nEnter elements of matrix B: \n");

for(i=0; i<rowB; i++){
for(j=0; j<colB; j++){
scanf("%d",&B[i][j]);
}
}

for(i=0; i<rowA; i++){
for(j=0; j<colB; j++){
sum[i][j]=0;
for(int k=0;k<colA;k++){
sum[i][j]+=A[i][k]*B[k][j];
}
}
}

printf("\nResultant matrix after multiplication: \n");

for(i=0; i<rowA; i++){
for(j=0; j<colB; j++){
printf("%d ",sum[i][j]);
}
printf("\n");
}
}

return 0;
}