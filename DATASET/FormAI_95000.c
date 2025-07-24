//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

void printRecursive(int num){
    if(num==0){
        return;
    }
    else{
        printf("%d ", num);
        printRecursive(num-1);
    }
}

int main(){
    int num;
    printf("Welcome to a fun-filled Recursive journey!\n");
    printf("Enter a positive integer to begin: ");
    scanf("%d", &num);
    printf("\n\nStarting countdown...\n");
    printRecursive(num);
    printf("\n\nBlast off!!!\n");
    return 0;
}