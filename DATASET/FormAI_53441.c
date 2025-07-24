//FormAI DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>

void recursive_printer(int n){
    if(n <= 0){
        return;
    }
    recursive_printer(n-1);
    for(int i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\n");
}

int main(){
    printf("Welcome to recursive printer!\n");
    printf("Enter the number of times to print the digits (1-10): ");
    int n;
    scanf("%d", &n);
    
    if(n < 1 || n > 10){
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        return 0;
    }
    
    printf("Starting recursive print:\n");
    recursive_printer(n);
    printf("Finished printing!\n");
    
    return 0;
}