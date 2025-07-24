//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

void fibonacci(int num_terms, int style){
    int a=0, b=1, c, i;
    
    printf("%d %d ", a, b); //printing the first two terms 
    
    for(i=2; i<num_terms; i++){
        c=a+b;
        a=b;
        b=c;
        
        if(style == 1){
            for(int j=0; j<c; j++){
                printf("*");
            }
        }
        else if(style == 2){
            printf("%d ", c);
        }
        else if(style == 3){
            printf("%d.%d%d ", c, i%10, i%5);
        }
    }
}

int main(){
    int num_terms, style;
    
    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);
    printf("\nEnter the style of visualization. Options: 1,2,3: ");
    scanf("%d", &style);
    
    fibonacci(num_terms, style);
    
    return 0;
}