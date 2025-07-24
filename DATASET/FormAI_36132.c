//FormAI DATASET v1.0 Category: Online Examination System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,rows,cols,m=0;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for(i=0;i<rows;i++){
        arr[i]=(int *)malloc(cols * sizeof(int));
    }
    printf("Enter the elements of the array: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Entered 2D array is : \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("Press 1 to exit.");
    scanf("%d",&m);
    return 0;
}