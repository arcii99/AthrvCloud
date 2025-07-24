//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include<stdio.h>

int find_sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+find_sum(n-1);
    }
}

int find_product(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*find_product(n-1);
    }
}
    
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(num<0){
        printf("Cannot calculate the sum and product of negative numbers\n");
    }
    else{
        int sum = find_sum(num);
        printf("Sum of first %d natural numbers = %d\n",num,sum);
        int product = find_product(num);
        printf("Product of first %d natural numbers = %d\n",num,product);
    }
    return 0;
}