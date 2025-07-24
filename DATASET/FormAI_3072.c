//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include<stdio.h>

int main(){
    int n,i;
    printf("Enter number of terms for Fibonacci sequence: ");
    scanf("%d",&n);
    
    int seq[n];
    seq[0]=0;
    seq[1]=1;
    
    for(i=2; i<n; i++){
        seq[i]=seq[i-1]+seq[i-2];
    }
    
    printf("The Fibonacci sequence for %d terms is:\n",n);
    for(i=0; i<n; i++){
        printf("%d ",seq[i]);
    }
    printf("\n");
    
    printf("The visualization of the Fibonacci sequence is shown below:\n");
    for(i=0; i<n; i++){
        int j, num=seq[i];
        for(j=0; j<num; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}