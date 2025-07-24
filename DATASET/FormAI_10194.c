//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int x=0;
    
    printf("Please enter a number: ");
    scanf("%d",&x);
    
    if(x<=0){
        printf("Invalid input. Terminating program.\n");
        exit(1);
    }
    else{
        int *z = malloc(x*sizeof(int));
        if(z==NULL){
            printf("Memory allocation error. Terminating program.\n");
            exit(1);
        }
        else{
            for(int i=0;i<x;i++){
                printf("Please enter an integer: ");
                scanf("%d",&z[i]);
                if(z[i]%2!=0){
                    printf("Error: Only even integers allowed. Terminating program.\n");
                    free(z);
                    exit(1);
                }
            }
            printf("All inputs accepted.\n");
            free(z);
        }
    }
    return 0;
}