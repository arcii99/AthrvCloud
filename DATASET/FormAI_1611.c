//FormAI DATASET v1.0 Category: Memory management ; Style: content
//This is a unique program using dynamic memory allocation in C. In this program, we will allocate memory dynamically to store elements of a 2-D array.

#include<stdio.h>
#include<stdlib.h>

int main(){

    int **arr;
    int rows,cols;
    int i,j;

    printf("Enter number of rows:");
    scanf("%d",&rows);

    printf("Enter number of columns:");
    scanf("%d",&cols);

    arr=(int**)malloc(rows*sizeof(int*));

    //allocate memory for columns
    for(i=0;i<rows;i++){
        arr[i]=(int*)malloc(cols*sizeof(int));
    }

    //Read 2-D array from user
    printf("Enter matrix %d x %d : \n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    //Display 2-D array
    printf("Matrix %d x %d : \n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    //Free dynamically allocated memory
    for(i=0;i<rows;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}