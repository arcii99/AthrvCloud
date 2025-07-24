//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n, i, j=0;
    printf("Enter the number of terms to be displayed in Fibonacci Series: ");
    scanf("%d",&n);
    printf("\n\n");
    printf("Let's visualize the Fibonacci Series in a unique way!\n\n\n");
    for(i=1; i<=n; i++){
        printf("%d\t|",i);
        int k, m;
        for(k=1; k<=j; k++){
            printf("\t");
        }
        for(m=0; m<=i-1; m++){
            printf(" %d\t",fibonacci(m));
        }
        printf("\n");
        j++;
    }
    printf("\n\n");
    return 0;
}