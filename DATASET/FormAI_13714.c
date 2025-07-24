//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

void recursiveFunction(int n){
    if (n <= 0){
        return;
    }
    else{
        printf("%d\n", n);
        recursiveFunction(n-1);
    }
}

int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    recursiveFunction(number);

    return 0;
}