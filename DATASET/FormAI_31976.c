//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include<stdio.h>

int drawTriangle(int n){
    if(n==1){ //base case
        printf("*\n");
    }else{
        drawTriangle(n-1); //recursive case
        for(int i=0; i<(2*n-1); i++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of the triangle: ");
    scanf("%d", &size);
    drawTriangle(size);
    return 0;
}