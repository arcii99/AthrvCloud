//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void recursive(int n){
    if(n < 0){
        printf("Error: Invalid number entered. Please enter a non-negative integer.\n");
        exit(1);
    }
    else if(n == 0){
        printf("Base Case Reached\n");
        return;
    }
    else{
        printf("Current Number: %d\n",n);
        recursive(n-1);
    }
}

int main(){
    int num;
    printf("Enter a non-negative integer: ");
    if(scanf("%d", &num) != 1){
        printf("Error: Invalid input entered. Please enter a non-negative integer.\n");
        exit(1);
    }
    recursive(num);
    return 0;
}