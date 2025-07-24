//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>

int fibonacci(int num){
    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }
    else{
        return (fibonacci(num-1)+fibonacci(num-2));
    }
}

int main(){
    int num;
    printf("Enter the number of terms: ");
    scanf("%d",&num);
    printf("Fibonacci Sequence for %d terms: \n\n",num);
    
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            printf("%d ", fibonacci(j));
        }
        printf("\n");
    }
    return 0;
}