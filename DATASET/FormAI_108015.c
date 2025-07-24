//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include<stdio.h>

void recursive_function(int num){
    if(num==0){
        printf("Blast off!\n");
        return;
    }
    printf("%d, ",num);
    recursive_function(num-1);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Initiating countdown...\n");
    recursive_function(n);
    return 0;
}