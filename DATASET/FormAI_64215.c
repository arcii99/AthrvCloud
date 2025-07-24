//FormAI DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include<stdio.h>

int main(){
    int rows, cols, n;

    printf("Enter number of rows:");
    scanf("%d", &n);

    rows=n/2+1;
    cols=n-rows+1;

    for (int i=1; i<=rows; i++){
        int temp=rows-i;
        for(int j=1; j<=temp; j++){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }

    for(int i=1; i<=cols; i++){
        for(int j=1; j<=i; j++){
            printf(" ");
        }
        for(int k=1; k<=cols-i+1; k++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}