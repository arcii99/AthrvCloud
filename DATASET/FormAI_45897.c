//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include<stdio.h>

void printPattern(int n, int c){
    if(n==0){
        return;
    }
    for(int i = 0; i < c; i++){
        printf("*");
    }
    printf("\n");
    printPattern(n-1, c+1);
    for(int i = 0; i < c-1; i++){
        printf("*");
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printPattern(n, 1);
    return 0;
}