//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include<stdio.h>

int main(){
    int n, i, c = 0, d = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series terms: ");
    for(i=1;i<=n;i++){
        if(i == 1){
            printf("%d, ", c);
            continue;
        }
        if(i == 2){
            printf("%d, ", d);
            continue;
        }
        nextTerm = c + d;
        c = d;
        d = nextTerm;
        printf("%d, ", nextTerm);
    }
    return 0;
}