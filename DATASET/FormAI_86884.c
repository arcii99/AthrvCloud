//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include<stdio.h>

int main(){
    int rows,cols,i,j,k;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);
    printf("\n");

    // printing the top half of pattern "C"
    for(i=0;i<rows/2;i++){
        // printing spaces before C
        for(j=0;j<cols/2;j++){
            printf(" ");
        }
        // printing C
        printf("C");
        // printing spaces after C
        for(j=0;j<cols/2;j++){
            printf(" ");
        }
        // moving to next line
        printf("\n");
    }
    // printing the middle line of pattern "C"
    for(i=0;i<cols;i++){
        printf("C");
    }
    // moving to next line
    printf("\n");
    // printing the bottom half of pattern "C"
    for(i=0;i<rows/2;i++){
        // printing spaces before C
        for(j=0;j<cols/2;j++){
            printf(" ");
        }
        // printing C
        printf("C");
        // printing spaces after C
        for(j=0;j<cols/2;j++){
            printf(" ");
        }
        // moving to next line
        printf("\n");
    }
    return 0;
}