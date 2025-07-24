//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int puzzling(int n){
    if(n==1){ //Base case
        return 1;
    }
    else if(n%2 == 0){ //If n is even
        printf("%d ",n);
        return puzzling(n/2);
    }
    else{ //If n is odd
        printf("%d ",n);
        return puzzling(3*n+1);
    }
}

int main(){
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    
    if(num<=0){
        printf("Invalid input!");
        exit(0);
    }
    else{
        printf("The sequence is: ");
        puzzling(num);
    }
    
    return 0;
}